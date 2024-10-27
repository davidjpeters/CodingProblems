#include <vector>
#include <string>

std::string smash(const std::vector<std::string>& words) {
    std::string ans;
    if (words.empty())
      return "";
  
    for (int i = 0; i < words.size(); ++i) {
      ans += words[i] + " ";
    }
    ans.pop_back();
  
   return ans;
}