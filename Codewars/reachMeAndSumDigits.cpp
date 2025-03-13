#include <vector>

int sumDigNthTerm(int initval, const std::vector<int> patternl, int nthterm) {
  
  int total = initval;
  
  for (int i = 0; ; ++i) {
    total += patternl[i % patternl.size()];
    
    if (i == nthterm - 2) 
      break;    
  }
  
  int sum = 0;
  while (total > 0) {
    sum += total % 10;
    total /= 10;
  }
  
  return sum;
}