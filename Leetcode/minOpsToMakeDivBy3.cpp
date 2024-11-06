#include <vector>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int n : nums) {
            if (n % 3 != 0)
                ops++;
        }
        return ops;
    }
};