#include <string>
#include <algorithm>

std::string solve(std::string s, int a, int b){
    
    if (b >= s.length())
      std::reverse(s.begin() + a, s.end());
    else
      std::reverse(s.begin() + a, s.begin() + b + 1);
      
    return s;
}