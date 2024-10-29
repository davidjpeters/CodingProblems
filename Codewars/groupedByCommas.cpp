#include <string>

std::string group_by_commas(int n) {
  
  std::string num = std::to_string(n);
  std::string ans = "";
  int l = num.length();
  
  if (l <= 3)
    return num;
  
  for (int i = 0; i < l; ++i) {
        ans += num[i];
        if ((l - i - 1) % 3 == 0 && (l - i - 1) != 0) {
            ans += ",";
        }
    }
  return ans;
}