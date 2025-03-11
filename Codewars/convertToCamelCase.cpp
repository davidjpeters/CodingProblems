#include <string>
#include <cctype>


std::string to_camel_case(std::string text) {
  std::string result = "";
  for (size_t i = 0; i < text.length(); ++i) {
    if (text[i] == '_' || text[i] == '-') {
      i += 1;
      result += toupper(text[i]);
    } else {
      result += text[i];
    }
  }
  return result;
}