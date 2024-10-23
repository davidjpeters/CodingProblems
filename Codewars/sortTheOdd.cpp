#include <algorithm>
#include <vector>

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array) {
      
      std::vector<int> oddIndices;
      std::vector<int> oddNums;
      
      for (int i = 0; i < array.size(); ++i) {
        if (array[i] % 2 == 1) {
          oddIndices.push_back(i);
          oddNums.push_back(array[i]);
        }
      }
      
      std::sort(oddNums.begin(), oddNums.end());
      
      for (int i = 0; i < oddIndices.size(); ++i) {
        array[oddIndices[i]] = oddNums[i];
    }
      
      return array;
    }
};