#include <string>
#include <vector>
#include <map>

class Solution {
public:
    std::string intToRoman(int num) {
        std::map<int, std::string> conversions = {{1000, "M"}, {900, "CM"}, {500, "D"},
                                            {400, "CD"}, {100, "C"}, {90, "XC"}, 
                                            {50, "L"}, {40, "XL"}, {10, "X"}, 
                                            {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
  
        std::vector<std::pair<int, std::string>> vec(conversions.begin(), conversions.end());

        std::sort(vec.begin(), vec.end(), std::greater<std::pair<int, std::string>>());
  
        std::string ans = "";
  
        while (num > 0) {
            for (auto p : vec) {
                if (p.first <= num) {
                    ans += p.second;
                    num -= p.first;
                    break;
                }
            }
        }
        return ans;
    }
};