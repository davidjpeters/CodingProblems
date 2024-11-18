#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int altitude = 0;
        int highest = altitude;

        for (const int& g : gain) {
            altitude += g;
            if (altitude > highest)
                highest = altitude;
        }
        return highest;
    }
};