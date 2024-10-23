#include <map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        std::map<int, std::string> conversions = {{1000, "M"}, {900, "CM"}, {500, "D"},
                                                  {400, "CD"}, {100, "C"}, {90, "XC"}, 
                                                  {50, "L"}, {40, "XL"}, {10, "X"}, 
                                                  {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        int ans = 0;

        for (auto it = conversions.rbegin(); it != conversions.rend(); ++it) {
            while (s.substr(0, it->second.length()) == it->second) {
                ans += it->first;
                s.erase(0, it->second.length());
            }
        }            

        return ans;
    }
};