#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

/*
No bag can fit inside another of the same size, so no list will contain duplicates
Create a frequency map counting the number of times each bag shows up. Initialize n lists
where n = number of times the most frequent element shows up. Then iterate over the 
frequency map, for each key, value pair (key = bag size, value = frequency), add `key` to the 
first `value` lists, since we only care that lists do not contain duplicates, but order and size
are irrelevant
*/

int main() {
    
    int num_of_bags = -1;
    while (std::cin >> num_of_bags && num_of_bags != 0) {

        std::unordered_map<int, int> frequencies;
        for (int i = 0; i < num_of_bags; ++i) {
            int bag;
            std::cin >> bag;
            frequencies[bag]++;
        }

        int highest_freq = 0;
        for (auto& f : frequencies)
            if (f.second > highest_freq)
                highest_freq = f.second;

        std::vector<std::stack<int>> lists(highest_freq);
        for (auto& f : frequencies) {
            for (int i = 0; i < f.second; ++i) {
                lists[i].push(f.first);
            }
        }
        std::cout << lists.size() << std::endl;
        for (auto& list : lists) {
            while (!list.empty()) {
                std::cout << list.top() << " ";
                list.pop();
            }
            std::cout << std::endl;
        }
    }
    return 0;
}