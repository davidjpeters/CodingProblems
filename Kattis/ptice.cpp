#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <tuple>

void updateScore(int, std::tuple<std::string, std::string, int>&, std::string);

int main () {

    std::vector<std::tuple<std::string, std::string, int>> students = {
        {"Adrian", "ABC", 0},
        {"Bruno", "BABC", 0},
        {"Goran", "CCAABB", 0}};

    int num_of_questions;
    std::string input;
    getline(std::cin, input);
    std::istringstream iss(input);
    iss >> num_of_questions;

    std::string answers;
    getline(std::cin, answers);

    for (int i = 0; i < num_of_questions; ++i) {
        for (auto& student : students) {
            updateScore(i, student, answers);
        }
    }

    int highest = std::max({std::get<2>(students[0]), std::get<2>(students[1]), std::get<2>(students[2])});

    std::cout << highest << std::endl;
    for (const auto& student : students) {
        if (std::get<2>(student) == highest)
            std::cout << std::get<0>(student) << std::endl;
    }
    return 0;
}

void updateScore(int i, std::tuple<std::string, std::string, int>& student, std::string answers) {
    std::get<2>(student) = (std::get<1>(student)[i % std::get<1>(student).length()] == answers[i])
        ? ++std::get<2>(student) : std::get<2>(student);
}