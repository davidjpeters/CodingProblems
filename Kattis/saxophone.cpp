#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <bitset>
#include <algorithm>
#include <ranges>

void readInput(int&, std::vector<std::string>&);

int main () {

    int num_of_songs;
    std::vector<std::string> songs;

    readInput(num_of_songs, songs);

    std::vector<int> num_of_presses; // keep track of note presses

    std::unordered_map<char, int> notes = { // store respective notes as binary strings
        {'c', 0b0111001111}, {'d', 0b0111001110}, {'e', 0b0111001100}, 
        {'f', 0b0111001000}, {'g', 0b0111000000}, {'a', 0b0110000000}, 
        {'b', 0b0100000000}, {'C', 0b0010000000}, {'D', 0b1111001110},
        {'E', 0b1111001100}, {'F', 0b1111001000}, {'G', 0b1111000000},
        {'A', 0b1110000000}, {'B', 0b1100000000}
    };

    for (int i = 0; i < num_of_songs; ++i) {
        // initialize vector of 0s for each finger
        int num_of_notes = songs[i].size();
        num_of_presses.assign(10, 0);
        // reset prev and curr for each iteration
        std::bitset<10> prev = 0b0000000000;
        std::bitset<10> curr = 0b0000000000;

        for (int j = 0; j < num_of_notes; ++j) {
            curr = notes[(char)songs[i][j]]; // set the current note
            std::bitset<10> temp = curr & ~prev; // get bits (fingers) that are in curr and NOT in prev
            prev = curr;
            for (int k = 0; k < temp.size(); ++k) {
                if (temp[k] == true) // if the bit (finger) is 1, it is a new keystroke
                    num_of_presses[k] += 1;
            }
        }
        std::ranges::reverse(num_of_presses); // bitset indexes from LSB, so order is reversed
        for (const auto& count : num_of_presses) {
            std::cout << count << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

void readInput(int& num_of_songs, std::vector<std::string>& songs) {
    std::string input;
    getline(std::cin, input);
    std::istringstream iss(input);
    iss >> num_of_songs;

    songs.reserve(num_of_songs); // reserve enough space for input
    while(getline(std::cin, input)) {
        songs.push_back(input); // add lines of notes (songs) to vector
    }
}