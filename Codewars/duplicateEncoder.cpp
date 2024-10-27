#include <string>
#include <map>

std::string duplicate_encoder(const std::string& word){
  
  std::map<char, int> letters;
  std::string ans = "";
  
  for (char c : word) 
    letters[tolower(c)]++;
  
  
  for (char c : word) {
    if (letters[tolower(c)] > 1)
      ans += ')';
    else
      ans += '(';
  }
  
  return ans;
}