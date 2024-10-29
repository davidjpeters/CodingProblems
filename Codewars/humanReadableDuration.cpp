#include <string>
#include <vector>

std::string format_duration(int seconds) {
  if (seconds == 0)
    return "now";
  
  std::vector<int> values = {31536000, 86400, 3600, 60, 1};
  std::vector<std::string> units = {"year", "day", "hour", "minute", "second"};
  std::vector<int> counts(5, 0);
  
  std::string ans = "";
  
  for (int i = 0; i < values.size(); ++i) {
    counts[i] = seconds / values[i];
    seconds %= values[i];
  }

  
  std::vector<std::string> parts;
  for (int i = 0; i < 5; ++i) {
    if (counts[i] > 1) {
      parts.push_back(std::to_string(counts[i]) + " " + units[i] + "s");
    }
    if (counts[i] == 1) {
      parts.push_back(std::to_string(counts[i]) + " " + units[i]);
    }
  }
  
  for (int i = 0; i < parts.size(); ++i) {
    if (i > 0) {
      if (i == parts.size() - 1) {
        ans += " and ";
      } else {
        ans += ", ";
      }
    }
    ans += parts[i];
  }
  return ans;
}