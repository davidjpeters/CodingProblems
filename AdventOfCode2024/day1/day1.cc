#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

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

    int total = 0;

    for (size_t i = 0; i < left.size(); ++i) {
        int diff = abs(left[i] - right[i]);
        total += diff;
    }

    std::cout << total;


    return 0;
}