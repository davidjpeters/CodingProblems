#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

int main() {

    int num_of_cases = 0;

    std::string num_of_cases_input;
    getline(std::cin, num_of_cases_input);
    std::istringstream iss(num_of_cases_input);
    iss >> num_of_cases;

    std::unordered_map<char, int> conversion = {
        {'a', 2}, {'b', 22}, {'c', 222}, 
        {'d', 3}, {'e', 33}, {'f', 333},
        {'g', 4}, {'h', 44}, {'i', 444},
        {'j', 5}, {'k', 55}, {'l', 555},
        {'m', 6}, {'n', 66}, {'o', 666},
        {'p', 7}, {'q', 77}, {'r', 777}, {'s', 7777},
        {'t', 8}, {'u', 88}, {'v', 888},
        {'w', 9},{'x', 99}, {'y', 999}, {'z', 9999},
        {' ', 0}
    };

    for (int i = 0; i < num_of_cases; ++i) {

        std::string message;
        getline(std::cin, message);
        std::cout << "Case #" << i + 1 << ": ";
        int last = 1;
        for (const char& c : message) {
            if (conversion[c] % 10 == last % 10)
                std::cout << ' ';
            std::cout << conversion[c];
            last = conversion[c];
        }
        std::cout << std::endl;
    }

    return 0;
}