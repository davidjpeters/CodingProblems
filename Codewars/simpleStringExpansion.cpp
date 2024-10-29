#include <string>

std::string string_expansion(const std::string& s) {
  std::string ans = "";
  int curr = 1;
  
  for (int i = 0; i < s.length(); ++i) {
    if (isdigit(s[i])) {
      curr = static_cast<int>(s[i] - '0');
      continue;
    } 
    std::string subStr(curr, s[i]);
    ans += subStr;
  }
  return ans;
}