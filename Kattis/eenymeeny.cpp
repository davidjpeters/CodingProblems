#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <sstream>

/*
Parse the input to determine number of words in the rhyme
Keep track of count for kids and where we are in the rhyme
Each time we reach the end of the rhyme, add the child to the 
alternating teams and remove them from the candidate list of children to
be chosen next
*/

int main() {

    int word_count = 0;
    std::string rhyme = "";

    if (std::getline(std::cin, rhyme)) {
        std::istringstream iss(rhyme);
        std::string word;
        while (iss >> word) {
            ++word_count;
        }
    }

    int num_of_kids = 0;
    std::cin >> num_of_kids;

    std::string name = "";
    std::vector<std::string> list_of_names;
    list_of_names.reserve(num_of_kids);

    while (std::cin >> name) {
        list_of_names.push_back(name);
    }

    int rhyme_count = 0;
    int current_index = 0;
    int current_team = 0;

    std::vector<std::string> teams[2];

    while (!list_of_names.empty()) {
        if (current_index >= list_of_names.size()) // if at the end of vector, wrap around
            current_index = 0;

        if (rhyme_count == word_count - 1) { // if we are at the end of the rhyme
            teams[current_team].push_back(list_of_names[current_index]); // add "chosen" child to team
            list_of_names.erase(list_of_names.begin() + current_index); // remove as candidate
            current_team ^= 1; // flip teams and reset count
            rhyme_count = 0;
        } else {
            current_index++; // increment the rhyme and the count
            rhyme_count++;
        }
    }

    for (const auto& team : teams) {
        std::cout << team.size() << std::endl;
        for (const auto& kid : team) {
            std::cout << kid << std::endl;
        }
    }

    return 0;
}