#include<vector>

bool isSmooth(const std::vector<int>& arr){
  int size = arr.size();
  
  if (size % 2 == 0) {
    if (arr[0] == arr[size - 1] && arr[0] == (arr[size/2] + arr[size/2 - 1]))
      return true;
  } else {
    if (arr[0] == arr[size - 1] && arr[0] == arr[size/2])
      return true;
  }
  
  return false;
}