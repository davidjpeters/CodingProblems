#include <iostream>

/*
Store values in unsigned 64 bit integer as long / long long
are not static between all architectures and OSs
Check which is larger, and subtract the smaller from the larger
to get the absolute difference
*/

int main () {

    uint64_t first;
    uint64_t second;

    while (std::cin >> first >> second) {
   
        if (first > second)
        std::cout << uint64_t(first - second) << std::endl;
        else 
        std::cout << uint64_t(second - first) << std::endl;
    }

    return 0;
}