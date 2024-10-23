#include <string>
#include <map>

std::string encode(const std::string &str) {
  
  std::map<char, int> convert = {{'a', '1'}, {'e', '2'}, {'i', '3'}, {'o', '4'}, {'u', '5'}};
  std::string encoded = "";
  
  for (char c : str) {
    if (convert.find(c) != convert.end()) {
      encoded += convert[c];
    } else {
      encoded += c;
    }
  }
  
  return encoded;
}

std::string decode(const std::string &str) {
  
  std::map<char, int> convert = {{'1', 'a'}, {'2', 'e'}, {'3', 'i'}, {'4', 'o'}, {'5', 'u'}};
  std::string decoded = "";
  
  for (char c : str) {
    if (convert.find(c) != convert.end()) {
      decoded += convert[c];
    } else {
      decoded += c;
    }
  }
  
  return decoded;
}