#include <string>

std::string solve(const std::string& str){
  int upper = 0;
  int lower = 0;
  
  std::string ans = "";
  
  for (char c : str) {
    if (static_cast<int>(c) < 97)
      upper++;
    else
      lower++;
  }
  
  if (lower >= upper)
    for (char c : str)
      ans += tolower(c);
  else
    for (char c : str)
      ans += toupper(c);
  
  return ans;
  
}