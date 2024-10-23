class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        long oneBelow = 2;
        long twoBelow = 1;
        long current = 0;

        for (int i = 2; i < n; ++i) {
            current = oneBelow + twoBelow;
            twoBelow = oneBelow;
            oneBelow = current;
        }
        return current;
    }
};