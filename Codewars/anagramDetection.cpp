#include <string>
#include <map>

bool isAnagram(std::string test, std::string original){
  if (test.length() != original.length())
    return false;
  
  std::map<char, int> first;
  std::map<char, int> second;
  
  for (int i = 0; i < test.length(); ++i) {
    first[tolower(test[i])]++;
    second[tolower(original[i])]++;
  }
  return first == second;
}