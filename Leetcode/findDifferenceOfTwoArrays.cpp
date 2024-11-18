#include <vector>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {

        std::set<int> a;
        std::set<int> b;
        std::vector<int> aDiff;
        std::vector<int> bDiff;

        for (auto n : nums1) {
            a.insert(n);
        }
        for (auto n : nums2) {
            b.insert(n);
        }

        std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(aDiff));
        std::set_difference(b.begin(), b.end(), a.begin(), a.end(), std::back_inserter(bDiff));
        
        return {aDiff, bDiff};
    }
};