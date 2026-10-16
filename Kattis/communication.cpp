#include <iostream>
#include <string>
#include <vector>
#include <sstream>
/*
Rather than decoding, there are 256 possibilities for each
byte value recieved. This is small enough that performing the 
original transformation and checking it against the recieved
value is trivial. Perform the transformation, mask with 0xFF 
to preserve just the bottom 8 bits, and compare. If they match 
then i prior to the transformation is the original transmission
*/

int main() {

    std::string bytes_input;
    getline(std::cin, bytes_input);
    int num_of_bytes = std::stoi(bytes_input);

    std::string input;
    getline(std::cin, input);
    std::istringstream iss(input);

    int byte;
    std::vector<int> bytes;
    bytes.reserve(num_of_bytes);
    while(iss >> byte) {
        bytes.push_back(byte);
    }

    for (const int byte : bytes) {
        for (int i = 0; i <= 255; ++i) {
            if ((i ^ ((i << 1) & 0xFF)) == byte)
                std::cout << i << " ";
        }
    }


    return 0;
}