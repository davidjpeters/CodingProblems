#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {

        auto it = std::max_element(candies.begin(), candies.end());
        int largest = *it;

        std::vector<bool> hasMostCandies(candies.size(), false);

        for (size_t i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= largest)
                hasMostCandies[i] = true;
        }
        return hasMostCandies;
    }
};