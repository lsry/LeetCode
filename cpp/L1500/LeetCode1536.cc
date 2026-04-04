#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<int> zeros(N, 0);
        for (int i = 0;i < N;++i) {
            for (int j = N - 1;j >= 0 && grid[i][j] == 0;--j) {
                zeros[i]++;
            }
        }
        int swapCount{0};
        for (int i = 0;i < N;++i) {
            if (zeros[i] >= N - 1 - i) {
                continue;
            }
            int j{i + 1};
            while (j < N && zeros[j] < N - 1 - i) {
                ++j;
            }
            if (j >= N) {
                return -1;
            }
            while (j > i) {
                std::swap(zeros[j - 1], zeros[j]);
                ++swapCount;
                --j;
            }
        }
        return swapCount;
    }
};
