#include <set>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::set<int> numbers;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (numbers.find(nums[i]) != numbers.end()) {
                nums.erase(nums.begin() + i);
            } else 
                numbers.insert(nums[i]);
        }
        return numbers.size();
    }
};