class Solution {
public:
    int addDigits(int num) {
        int copy = num;
        int ans = 0;
        if (num < 10)
            return num;

        while (true) {
            int temp = 0;
            while (copy > 0) {
                temp += copy % 10;
                copy /= 10;
            }
            if (temp < 10)
                return temp;
            copy = temp;
        }
    return ans;
    }
};