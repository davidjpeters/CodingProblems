#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string s : operations) {
            if (s[0] == '+' || s[2] == '+')
                x++;
            else
                x--;
        }
        return x;
    }
};