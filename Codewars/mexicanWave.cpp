#include <string>
#include <vector>

std::vector<std::string> wave(std::string y){
  
  std::vector<std::string> ans;
  
  for (int i = 0; i < y.length(); ++i) {
    if (y[i] == ' ')
      continue;
    std::string temp = y;
    temp[i] = toupper(temp[i]);
    ans.push_back(temp);
  }
  return ans;
}