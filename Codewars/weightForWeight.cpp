#include <cctype>
#include <vector>
#include <string>
#include <map>

class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng) {
      
      std::vector<std::string> numbers;
      
      for (int i = 0; i < strng.length(); ++i) {
        if (isdigit(strng[i])) {
          int j = i;
          while (j < strng.length() && isdigit(strng[j])) {
            ++j;
          }
        std::string temp = strng.substr(i, j - i);
        numbers.push_back(temp);
        i = j - 1;
        }
      }
      
      auto weightCompare = [](const std::string& a, const std::string& b) {
            int weightA = 0, weightB = 0;
            for (char c : a) weightA += c - '0';
            for (char c : b) weightB += c - '0';
            
            if (weightA != weightB) {
                return weightA < weightB;
            }
            return a < b;
        };
        
        std::sort(numbers.begin(), numbers.end(), weightCompare);
        
        std::string result;
        for (const auto& num : numbers) {
            if (!result.empty()) result += " ";
            result += num;
        }
        
        return result;
    }
};
