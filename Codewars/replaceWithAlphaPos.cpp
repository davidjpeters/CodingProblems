#include <string>

std::string alphabet_position(const std::string &text) {
  std::string ans = "";
  for(int i = 0; i < text.length(); ++i) {
    if (isalpha(text[i])) {
      int pos = tolower(text[i]) - 'a' + 1;
      ans += std::to_string(pos) + " ";
    }
  }
  if (!ans.empty())
    ans.pop_back();
  return ans;
}