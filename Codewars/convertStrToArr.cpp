#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> string_to_array(const std::string& s) {
  
    std::vector<std::string> words;
  
    for (size_t i = 0; i < s.length(); ++i) {
      if (std::isalnum(s[i])) {
        size_t j = i;
        while (std::isalnum(s[j])) {
          j++;
        }
        std::string temp = s.substr(i, j - i);
        words.push_back(temp);
        i = j;
      }
    }
  
    if (words.empty())
      words.push_back("");    
    
    return words;
}