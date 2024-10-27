#include <string>
#include <set>

int solve(std::string s) {
  std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
	int longest = 0;
  int curr = 0;
  for (char c : s) {
    if (vowels.find(c) != vowels.end()) {
      curr++;
    if (curr > longest)
      longest = curr;
      continue;
    }
    curr = 0;
  }
  return longest;
}