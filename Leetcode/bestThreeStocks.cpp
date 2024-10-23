#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>


int main() {

    std::vector<std::string> stocks = {"AMZN", "GOOG", "SHOP", "META", "FLIX"};

    std::vector<std::vector<float>> prices = {{10.42, 9.89, 12.71, 15.45, 8.87},
                                            {13.42, 17.89, 14.71, 11.45, 18.87},
                                            {15.42, 8.89, 10.71, 12.45, 12.87},
                                            {11.42, 12.89, 18.71, 13.45, 13.87}};

    

    std::vector<float> total_prices = {};

    for (int i = 0; i < stocks.size(); i++) {
        float total = 0.0;
        for (int j = 0; j < prices.size(); j++) {
            total += prices[j][i];
        }
        total_prices.push_back(total/prices.size());
    }

    std::map<float, std::string> map;

    for (int i = 0; i < stocks.size(); i++) {
        map[total_prices[i]] = stocks[i];
    }

    auto it = map.rbegin();

    for (int i = 0; i < 3; i++) {
        std::cout << it->second << std::endl;
        ++it;
    }

    for (auto& pair : map)
        std::cout << pair.first << " " << pair.second << std::endl;

    return 0;
}