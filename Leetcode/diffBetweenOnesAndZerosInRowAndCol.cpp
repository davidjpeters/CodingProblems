#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

          int m = grid.size();
    int n = grid[0].size();

    // Initialize rows and cols with the correct sizes
    vector<int> rows(m, 0);
    vector<int> cols(n, 0);

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    rows[i]++;
                else
                    rows[i]--;
            }
        }


        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] == 1)
                    cols[i]++;
                else
                    cols[i]--;
            }
        }
        
        vector<vector<int> > diff(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < diff.size(); i++) {
            for (int j = 0; j < diff[0].size(); j++) {
                diff[i][j] = rows[i] + cols[j];
            }
        }


    return diff;
    }
};