#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>

/*
With 6! = 720 potential answers, and a guaranteed unique solution,
checking each possible permutation is quick enough and easy to understand.
Read in the input, and then for each permutation, check if the first 3 boxes
equal the height of tower 1, and the last 3 equal the height of tower 2. Sort input
first so next_permutation checks all possibilities, and then sort descending each half
of the successful permutation to get the desired output format
*/

int main() {

    int input;
    int tower_one_height;
    int tower_two_height;

    std::vector<int> boxes;

    for (int i = 0; i < 6; ++i) {
        std::cin >> input;
        boxes.push_back(input);
    }
    std::cin >> tower_one_height >> tower_two_height;
    std::sort(boxes.begin(), boxes.end());

    do {
        if (std::accumulate(boxes.begin(), boxes.begin() + 3, 0) == tower_one_height
            && std::accumulate(boxes.begin() + 3, boxes.end(), 0) == tower_two_height) {
                break;
            }
    } while (std::next_permutation(boxes.begin(), boxes.end()));

    std::sort(boxes.begin(), boxes.begin() + 3, std::greater<>());
    std::sort(boxes.begin() + 3, boxes.end(), std::greater<>());

    for (const int box : boxes) {
        std::cout << box << " ";
    }

    return 0;
}