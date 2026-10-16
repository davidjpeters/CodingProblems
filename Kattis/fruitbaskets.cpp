#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>

/*
Fruits have a minimum weight of 50, so any 4 fruits MUST be >= 200, i.e. we
are going to trim most of the possible solutions for large N. Also if we keep 
track of remaining weights, if the current weight + remaining < 200, prune as
there is no way to get to 200. Recursively:
1. Call sumBasket() with and without the current fruit added to current weight (choose or not choose)
2. 
    a) current weight is sufficient, all remaining fruits can be included (2^n possible baskets : n = remaining fruits)
    so: current_weight * num_baskets + remaining_weight * (num_baskets/2)
         current_weight * num_baskets : fruit is selected and is present in each basket
         remaining_weight * (num_baskets/2) : each fruit not yet chosen shows up in exactly half of baskets
    b) current weight + remaining weight is insufficient, no way to get to minimum weight limit, continue
*/

const int MIN_WEIGHT = 200;
long long sumBaskets(std::vector<long long>& weights, int index, long long current_weight);

int main() {

    int num_of_fruits;
    std::cin >> num_of_fruits;

    std::vector<long long> weights(num_of_fruits);

    for (int i = 0; i < num_of_fruits; ++i) {
        std::cin >> weights[i];
    }

    std::cout << sumBaskets(weights, 0, 0);

    return 0;
}

long long sumBaskets(std::vector<long long>& weights, int index, long long current_weight) {
    int fruits_left = weights.size() - index;
    long long remaining_weight = std::accumulate(weights.begin() + index, weights.end(), 0);

    if (current_weight >= MIN_WEIGHT) {
        long long num_baskets = pow(2, fruits_left);

        return current_weight * num_baskets + remaining_weight * (num_baskets / 2);
    }

    if (current_weight + remaining_weight < MIN_WEIGHT) return 0;

    return sumBaskets(weights, index + 1, current_weight + weights[index])
        + sumBaskets(weights, index + 1, current_weight);
    
}