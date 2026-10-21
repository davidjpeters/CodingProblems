#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <queue>

/*
Start by sorting by driving time in non-increasing order, and take the fastest k
(k = number of cars) drivers (any k+1 driver will have to wait for a car to return
anyway, at which point the faster driver would be driving back regardless). Store these
drivers in a min heap sorted by arrival time starting at the time it takes the to drive t,
the time for a one way trip, incrementing by 2 everytime (t to get to the stadium, then
t += 2 to go back home and to the stadium again). If it's their first trip, include them 
in the count, if not exclude them. Pop the heap since they've driven and add their time back
in multiplied by 
*/

int main() {

    int people, cars;
    std::cin >> people >> cars;

    std::vector<uint64_t> drivers(people);
    for (uint64_t& driver : drivers)
        std::cin >> driver;
    std::sort(drivers.begin(), drivers.end());

    std::priority_queue<std::pair<uint64_t, int>, std::vector<std::pair<uint64_t, int>>, std::greater<std::pair<uint64_t, int>>> times;
    for (int i = 0; i < std::min(people, cars); ++i)
        times.push({drivers[i], 1});

    int arrived = 0;
    uint64_t last = 0;;
    while (arrived < people) {
        if (times.top().second == 1) {
            std::pair<uint64_t, int> fastest = times.top();
            times.pop();
            arrived += 5;
            last = fastest.first;
            times.push({fastest.first + 2 * (fastest.first / fastest.second), fastest.second + 2});
        } else {
            std::pair<uint64_t, int> fastest = times.top();
            times.pop();
            arrived += 4;
            last = fastest.first;
            times.push({fastest.first + 2 * (fastest.first / fastest.second), fastest.second + 2});
        }
    }    
    std::cout << last;

    return 0;
}
