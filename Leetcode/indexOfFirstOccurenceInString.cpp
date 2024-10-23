#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int length = needle.length();
        int i = 0;
        while (haystack.length() >= length) {
            std::string temp = haystack.substr(0, length);
            if (temp == needle) {
                return i;
            }
            haystack.erase(0, 1);
            i++;
        }
        return -1;
    }
};