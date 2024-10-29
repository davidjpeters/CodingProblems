#include <string>
#include <vector>
#include <map>
std::string solution(int number){
  std::map<int, std::string> conversions = {{1000, "M"}, {900, "CM"}, {500, "D"},
                                            {400, "CD"}, {100, "C"}, {90, "XC"}, 
                                            {50, "L"}, {40, "XL"}, {10, "X"}, 
                                            {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
  
  std::vector<std::pair<int, std::string>> vec(conversions.begin(), conversions.end());

  std::sort(vec.begin(), vec.end(), std::greater<std::pair<int, std::string>>());
  
  std::string ans = "";
  
  while (number > 0) {
    for (auto p : vec) {
      if (p.first <= number) {
        ans += p.second;
        number -= p.first;
        break;
      }
    }
  }
  return ans;
}