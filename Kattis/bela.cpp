#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

void getInput(int& num_of_hands, char& dominant_suit, std::vector<std::string>& hands);

int main() {

    
    int num_of_hands;
    char dominant_suit;
    std::vector<std::string> hands;
    
    getInput(num_of_hands, dominant_suit, hands);

    // using two maps to avoid multiple if else statements in the main loop, make it a single check
    std::unordered_map<char, int> not_dominant = {
        {'A', 11}, {'K', 4}, {'Q', 3},
        {'J', 2}, {'T', 10}, {'9', 0},
        {'8', 0}, {'7', 0}
    };
    std::unordered_map<char, int> dominant = {
        {'A', 11}, {'K', 4}, {'Q', 3},
        {'J', 20}, {'T', 10}, {'9', 14},
        {'8', 0}, {'7', 0}
    };

    int total_points = 0;
    for (const std::string hand : hands) { 
        if (hand[1] == dominant_suit) 
            total_points += dominant[hand[0]]; // if hand is dominant use dominant table
        else
            total_points += not_dominant[hand[0]]; // if not dominant, use standard table
    }

    std::cout << total_points;

    return 0;
}

void getInput(int& num_of_hands, char& dominant_suit, std::vector<std::string>& hands) {
    std::string input;
    getline(std::cin, input);
    std::istringstream iss(input);

    iss >> num_of_hands >> dominant_suit;

    hands.reserve(4 * num_of_hands); // reserve enough space to avoid reallocating memory (1 hand = 4 cards)

    while (getline(std::cin, input)) {
        hands.push_back(input);
    }
}