#include <vector>
#include <string>

std::vector<int> parse(const std::string &data) {
  
  std::vector<int> ans;
  int value = 0;
  
  for (const char& c : data) {
    if (c == 'i')
      value++;
    if (c == 'd')
      value--;
    if (c == 's')
      value *= value;
    if (c == 'o')
      ans.push_back(value);
  }
  return ans;
}