#include <string>
#include <map>

bool hasUniqueChars(std::string s) {
  std::map<char, int> chars;
  for (char c : s) {
    chars[c]++;
  }
  for (auto p : chars) {
    if (p.second > 1)
      return false;
  }
  return true;
}