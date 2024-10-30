#include <string>

std::string pofi(unsigned n) {
  std::string ans = "";
  
  ans = n % 2 == 0 ? "1" : "i";
  
  return n % 4 == 2 || n % 4 == 3 ? "-" + ans : ans;
}