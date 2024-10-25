#include <vector>
#include <map>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::map<int, int> numbers;
        for (const int& n : nums) {
            numbers[n]++;
        }
        for (const auto& num : numbers) {
            if (num.second > 1)
                return true;
        }
        return false;
    }
};