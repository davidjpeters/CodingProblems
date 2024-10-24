#include <vector>
#include <map>

int findOdd(const std::vector<int>& numbers){
  std::map<int, int> counts;
  
  for (const int num : numbers) {
    counts[num]++;
  }
  for (auto& it : counts) {
    if (it.second % 2 == 1)
      return it.first;
  }
  return -1;
}