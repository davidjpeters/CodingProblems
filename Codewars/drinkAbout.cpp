#include <string>

std::string people_with_age_drink(int age) {
  std::string ans = "drink ";
  
  if (age < 14)
    ans += "toddy";
  else if (age < 18) 
    ans += "coke";
  else if (age < 21) 
    ans += "beer";
  else
    ans += "whisky";

  return ans;
}