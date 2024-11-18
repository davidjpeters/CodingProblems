#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        if (s.length() == 0)
            return true;
        if (s.length() > t.length()) 
            return false;

        int subIndex = 0;

        for (int i = 0; i < t.length(); ++i) {
            if (t[i] == s[subIndex]) {
                subIndex++;
            }

            if (subIndex == s.length())
                return true;
        }

        return false;
        
    }
}; 