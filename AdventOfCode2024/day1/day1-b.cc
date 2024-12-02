#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

int main() {
    
    std::vector<int> left;
    std::vector<int> right;

    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    int val1, val2;

    while (file >> val1 >> val2) {
        left.push_back(val1);
        right.push_back(val2);
    }

    file.close();

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    std::map<int, int> rightSide;

    for (const auto& n : right) {
        rightSide[n]++;
    }

    int total = 0;
    for (const auto& n : left) {
         auto it = rightSide.find(n);
        if (it != rightSide.end()) 
            total += n * it->second; 
    
    }



    std::cout << total;


    return 0;
}