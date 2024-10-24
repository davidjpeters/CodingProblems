#include <string>
#include <set>

using namespace std;

int getCount(const string& inputStr){
  int num_vowels = 0;
  
  std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  
  for (auto& c : inputStr)
    if (find(vowels.begin(), vowels.end(), c) != vowels.end())
      num_vowels++;
  
  return num_vowels;
}