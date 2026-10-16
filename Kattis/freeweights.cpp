#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/*
We can organize the racks moving only weights of a certain weight W, even if we 
encounter heavier weights that are not paired up, provided that the weights between
that one and its partner CAN all be moved (i.e. W = 3, {1, 8, 1, 8} is fine b/c we
can move the 1 and slide the 8). Use open = -1 to keep track of unmatched pairs. If
we encounter a weight we cannot move, set open to that weight. We will either run
into its match, encounter a weight that's too heavy and return false, or reach the end 
of the row (the weights match is on the other rack and we cannot move it) and return false
If both rows pass, we can lower our weight threshold, if either fail, raise it, until
the search terminates
*/

bool checkRow(int, std::vector<int>&);
bool check(int, std::vector<int>&, std::vector<int>&);

int main() {

    int num_of_pairs;
    std::cin >> num_of_pairs;

    std::vector<int> top(num_of_pairs), bottom(num_of_pairs);

    for (int& w : top)
        std::cin >> w;
    for (int& w : bottom) {
        std::cin >> w;
    }

    int lo = 0;
    int hi = std::max(*std::max_element(top.begin(), top.end()),
            *std::max_element(bottom.begin(), bottom.end()));


    if (check(0, top, bottom)) {
        std::cout << 0;
        return 0;
    }

    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, top, bottom))
            hi = mid;
        else
            lo = mid;
    }

    std::cout << hi;

    return 0;
}

bool checkRow(int mid, std::vector<int>& row) {

    int open = -1;
    for (int i = 0; i < row.size(); ++i) {
        if (row[i] <= mid) continue;
        if (open == -1)
            open = row[i];
        else if (row[i] == open)
            open = -1;
        else
            return false;
    }
    return open == -1;
}

bool check(int mid, std::vector<int>& top, std::vector<int>& bottom) {
    return checkRow(mid, top) && checkRow(mid, bottom);
}