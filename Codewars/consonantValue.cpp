#include <string>
#include <set>

int solve(const std::string &s) {
  std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  
  int largest = 0;
  int current = 0;
  
  for (int i = 0; i < s.size(); ++i) {
    if (current > largest)
      largest = current;
    
    if (vowels.find(s[i]) != vowels.end()) {
      current = 0;
      continue;
    }
    
    current += s[i] - 'a' + 1;
  }
  
  if (current > largest)
    return current;
  
  return largest;
}