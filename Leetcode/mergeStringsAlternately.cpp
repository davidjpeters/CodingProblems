#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string ans = "";
        int i = 0;
        for (; i < min(word1.length(), word2.length()); ++i) {
            ans += word1[i];
            ans += word2[i];
        }

        if (word1.length() == word2.length()) return ans;

        if (word1.length() < word2.length()) {
            ans += word2.substr(i, word2.length() - 1);
        } else {
            ans += word1.substr(i, word1.length() - 1);
        }
        return ans;
    }
};