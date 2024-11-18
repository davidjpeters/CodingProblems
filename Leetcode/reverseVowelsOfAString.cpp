#include <string>
#include <set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {

        std::set<char> vowels = { 'a', 'e', 'i', 'o', 'u'};

        int i = 0, j = s.length() - 1;

        while (i < j) {
            if (!vowels.count(tolower(s[i])) > 0) 
                i++;
            if (!vowels.count(tolower(s[j])) > 0) 
                j--;

            if (vowels.count(tolower(s[i])) > 0 && vowels.count(tolower(s[j])) > 0)  {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};