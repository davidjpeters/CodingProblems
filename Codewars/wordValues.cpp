#include <string>
#include <vector>

std::vector<int> wordValue(std::vector <std::string> arr){
	std::vector<int> ans;
  
  for (int i = 0; i < arr.size(); ++i) {
    
    int total = 0;
    std::string str = arr[i];
    
    for (int j = 0; j < str.length(); ++j) {
      if (isalpha(str[j]))
        total += str[j] - 'a' + 1;
    }
    
    ans.push_back(total * (i + 1));
  }
  return ans;
}