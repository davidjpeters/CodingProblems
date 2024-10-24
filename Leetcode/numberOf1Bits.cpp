#include <string>
#include <bitset>

class Solution {
public:
    int hammingWeight(int n) {

    std::string binary = std::bitset<32>(n).to_string();

    int count = 0;
    for (char c : binary) {
        if (c == '1')
            count++;
    }
    return count;
    }
};