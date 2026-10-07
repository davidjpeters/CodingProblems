#include <iostream>
#include <algorithm>


/*
 * Fenwick Tree
 *
 * Author: Howard Cheng
 * Reference:
 *
 *   Fenwick, P.M. "A New Data Structure for Cumulative Frequency Tables."
 *   Software---Practice and Experience, 24(3), 327-336 (March 1994).
 *
 * This code has been tested on UVa 11525 and 11610.
 *
 * Fenwick trees are data structures that allows the maintainence of
 * cumulative sum tables dynamically.  The following operations
 * are supported:
 *
 * - Initialize the tree from a list of N integers:                 O(N log N)
 *
 * - Read the cumulative sum at index 0 <= k < N:                   O(log k)
 *
 * - Read the entry at index 0 <= k < N:                            O(log N)
 *
 * - Increment/decrement an entry at index 0 <= k < N in the list:  O(log N)
 *
 * - Given a value, find an index such that the cumulative sum at
 *   that position is the value:                                    O(log N)
 *
 * The space usage is at most 2*N for N input entries.
 *
 * NOTE: it is assumed that all entries are non-negative (even after a
 *       decrement operation).
 *
 */

#include <vector>
#include <cassert>

using namespace std;

class FenwickTree
{
public:
  FenwickTree(int n = 0)
    : N(n), tree(n)
  {
    iBM = 1;
    while (iBM < N) {
      iBM *= 2;
    }
    tree.resize(iBM+1);
    fill(tree.begin(), tree.end(), 0);
  }

  // initialize the tree with the given array of values
  FenwickTree(int val[], int n)
    : N(n)
  {
    iBM = 1;
    while (iBM < N) {
      iBM *= 2;
    }
    
    tree.resize(iBM+1);
    fill(tree.begin(), tree.end(), 0);
    for (int i = 0; i < n; i++) {
      assert(val[i] >= 0);
      incEntry(i, val[i]);
    }
  }

  // increment the entry at position idx by val (use negative val for
  // decrement).  All affected cumulative sums are updated.
  void incEntry(int idx, int val)
  {
    assert(0 <= idx && idx < N);
    if (idx == 0) {
      tree[idx] += val;
    } else {
      do {
	tree[idx] += val;
	idx += idx & (-idx);
      } while (idx < (int)tree.size());
    }
  }

  // return the cumulative sum val[0] + val[1] + ... + val[idx]
  int cumulativeSum(int idx) const
  {
    assert(0 <= idx && idx < (int)tree.size());
    int sum = tree[0];
    while (idx > 0) {
      sum += tree[idx];
      idx &= idx-1;
    }
    return sum;
  }

  // return the entry indexed by idx
  int getEntry(int idx) const
  {
    assert(0 <= idx && idx < N);
    int val, parent;
    val = tree[idx];
    if (idx > 0) {
      parent = idx & (idx-1);
      idx--;
      while (parent != idx) {
	val -= tree[idx];
	idx &= idx-1;
      }
    }
    return val;
  }

  // return the largest index such that the cumulative frequency is
  // what is given, or -1 if it is not found
  //
  int getIndex(int sum) const
  {
    int orig = sum;
    if (sum < tree[0]) return -1;
    sum -= tree[0];
    
    int idx = 0;
    int bitmask = iBM;

    while (bitmask != 0 && idx < (int)tree.size()-1) {
      int tIdx = idx + bitmask;
      if (sum >= tree[tIdx]) {
	idx = tIdx;
	sum -= tree[tIdx];
      }
      bitmask >>= 1;
    }

    if (sum != 0) {
      return -1;
    }

    idx = min(N-1, idx);
    return (cumulativeSum(idx) == orig) ? idx : -1;
  }
  
private:
  int N, iBM;
  vector<int> tree;
};

int main() {

    int num_of_elements;
    std::cin >> num_of_elements;
    int small = 1;
    int large = num_of_elements;

    std::vector<int> pos_array(num_of_elements + 1, 0);
    FenwickTree ft(num_of_elements);

    for (int i = 0; i < num_of_elements; ++i) {
      int input;
      std::cin >> input;
      // store elements as value -> index ({3, 1, 2} -> {2, 3, 1})
      pos_array[input] = i; 
      ft.incEntry(i, 1); // initialize tree with 1s
    }
    for (auto x : pos_array) {
      std::cout << x << " " << std::endl;
    }
    std::cout << "here";
    // when a number moves to either end, it is "out of play", it doesn't
    // change the relative order, everything shifts with it. Decrement a 
    // placed numbers entry in fenwick tree, as an unmoved number will never
    // swap with an already moved number
    int phase_swaps = 0;
    int remaining = num_of_elements; // keep track of how many unmoved elements there are
    for (int i = 1; i <= num_of_elements; ++i) {
      if (i % 2 == 0) { // even phase (moving largest unmoved number)
        // get the original index of element
        int pos = pos_array[large];
        // # of swaps = # of unmoved numbers - sum up to pos 
        // (i.e. total swaps - swaps to the left = swaps to the right)
        phase_swaps = remaining - ft.cumulativeSum(pos);
        // set entry 1 -> 0
        ft.incEntry(pos, -1);
        // decrement number to get next even phase target
        large--;
      } else { // odd phase (moving smallest unmoved element)
        // get original index of element
        int pos = pos_array[small];
        // cumulative sum = # of swaps to the left (exclusive of element itself)
        phase_swaps = ft.cumulativeSum(pos) - 1;
        // set entry 1 -> 0
        ft.incEntry(pos, -1);
        // increment small number to get next odd phase target
        small++;
      }
      remaining--; // decrement, keep track of total unmoved numbers
      std::cout << phase_swaps << '\n';
    }



    

    return 0;
}