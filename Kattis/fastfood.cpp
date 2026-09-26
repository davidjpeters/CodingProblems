#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

/*
Created structs to organize cases and prizes
For calculating value, since no stickers are used
for multiple prizes, find the tickets used for a prize
and the corresponding player ticket with the smallest
quantity, and this is how many times that ticket can
be redeemed. Summing this across all prizes results in
in the total highest redeemable value
*/


struct Prize {
    int num_sticker_types;
    std::vector<int> stickers;
    int value;
};

struct Case {
    int num_prizes;
    int num_stickers;
    std::vector<Prize> prizes;
    std::vector<int> player_stickers;
};

void readCase(Case& c);
int calculateValue(Case& c);

int main() {

    std::string line;
    getline(std::cin, line);
    int num_of_cases = std::stoi(line);

    std::vector<Case> cases(num_of_cases);

    for (int i = 0; i < num_of_cases; ++i) {        
        readCase(cases[i]);
        std::cout << calculateValue(cases[i]) << std::endl;
    }
    
    return 0;
}

void readCase(Case& c) {
    std::string line;
    getline(std::cin, line);
    std::stringstream iss(line);
    iss >> c.num_prizes >> c.num_stickers;

    c.prizes.resize(c.num_prizes);

    for (int i = 0; i < c.num_prizes; ++i) {
        std::string prize_info;
        getline(std::cin, prize_info);
        std::stringstream input(prize_info);

        input >> c.prizes[i].num_sticker_types;
        c.prizes[i].stickers.resize(c.prizes[i].num_sticker_types);
        for (int j = 0; j < c.prizes[i].num_sticker_types; ++j) {
            input >> c.prizes[i].stickers[j];
        }
        input >> c.prizes[i].value;
    }
    std::string player_stickers;
    getline(std::cin, player_stickers);
    std::stringstream ss(player_stickers);
    int temp;
    while (ss >> temp) {
        c.player_stickers.push_back(temp);
    }
}

int calculateValue(Case& c) {
    int total_value = 0;
    for (int i = 0; i < c.num_prizes; ++i) {
        int smallest = 101;

        for (const auto s : c.prizes[i].stickers) {
            if (smallest > c.player_stickers[s - 1]) smallest = c.player_stickers[s - 1];
        }
    total_value += smallest * c.prizes[i].value;
    }
    return total_value;
}