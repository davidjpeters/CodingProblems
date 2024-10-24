#include <cmath>

bool narcissistic( int value ){
  int digits = 0;
  int copy = value;
  
  while (copy > 0) {
    copy /= 10;
    digits++;
  }
  copy = value;
  int sum = 0;
  while (copy > 0) {
    sum += pow(copy % 10, digits);
    copy /= 10;
  }
  
  return sum == value;
}