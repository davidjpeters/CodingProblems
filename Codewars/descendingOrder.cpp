#include <cinttypes>
#include <vector>
#include <algorithm>

uint64_t descendingOrder(uint64_t a)
{
  std::vector<char> digits;
  while (a > 0) {
    digits.push_back(static_cast<char>(a % 10));
    a /= 10;
  }
  
  sort(digits.begin(), digits.end(), std::greater());
  
  uint64_t greatest = 0;
  for (size_t i = 0; i < digits.size(); ++i) {
    greatest *= 10;
    greatest += digits[i];
  }
  
  return greatest;
}