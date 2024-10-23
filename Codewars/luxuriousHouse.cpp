#include <vector>

std::vector<int> luxhouse(const std::vector<int> &houses) {
  std::vector<int> floors(houses.size(), 0);
  int largest = houses[houses.size() - 1];
  
  
  for (int i = houses.size() - 2; i >= 0; --i) {
    
    if (houses[i] <= largest) 
      floors[i] = largest + 1 - houses[i];
    
    if (houses[i] > largest || largest == 0)
      largest = houses[i];
  }
  
  return floors;
}