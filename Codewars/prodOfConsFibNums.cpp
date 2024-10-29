#include <vector>
#include <cmath>
typedef unsigned long long ull;
class ProdFib
{
public:
  static std::vector<ull> productFib(ull prod) {
  
    if (prod == 0) 
      return {0, 0, true};
    
    unsigned long long one = 1;
    unsigned long long two = 0;
    
    while (one * two < prod) {
      unsigned long long temp = one;
      one += two;
      two = temp;
    }
    
    if (one * two == prod) 
      return {two, one, true};

  
  return {two, one, false};
  }
};