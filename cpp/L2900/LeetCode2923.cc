#include <vector>
using std::vector;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<int> beats(N, 0);
        for (int i = 0;i < N;++i) {
            for (int j = i + 1;j < N;++j) {
                if (grid[i][j] == 1) {
                    beats[i] += 1;
                } else {
                    beats[j] += 1;
                }
            }
        }
        for (int i = 0;i < N;++i) {
            if (beats[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};