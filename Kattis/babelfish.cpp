#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>
#include <ranges>

/*
Create a dictionary (unorderd map) of foreign words -> english words via input
Collect the message string, and for each word:
if it is present in the dictionary, replace it with the translated word
if it is not found, output "eh"
*/

int main() {

    std::string dict_entry;
    std::unordered_map<std::string, std::string> dict;

    std::string english;
    std::string foreign;
    
    while (std::getline(std::cin, dict_entry) && !dict_entry.empty()) {
        std::stringstream iss(dict_entry);
        iss >> english >> foreign;

        dict[foreign] = english;
    }

    std::string message_word;
    while (std::cin >> message_word) {

        if (auto translated = dict.find(message_word); translated != dict.end())
            std::cout << translated->second << std::endl;
        else
            std::cout << "eh" << std::endl;

    }


    return 0;
}