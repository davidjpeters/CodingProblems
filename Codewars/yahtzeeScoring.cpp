#include <vector>
#include <map>

long yahtzee_upper(std::vector<int> arr) {
  std::map<int, int> map;
  for (auto n : arr) {
    map[n]++;
  }
  
  int largest = 0;
  
  for (auto p : map) {
    if (p.first * p.second > largest)
      largest = p.first * p.second;
  }
  return largest;
}