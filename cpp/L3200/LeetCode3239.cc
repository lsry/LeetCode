#include <vector>
using std::vector;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        int a{0}, b{0};
        for (int i = 0;i < M;++i) {
            for (int low{0}, high{N - 1};low < high;++low, --high) {
                if (grid[i][low] != grid[i][high]) {
                    ++a;
                }
            }
        }
        for (int j = 0;j < N;++j) {
            for (int low{0}, high{M - 1};low < high;++low, --high) {
                if (grid[low][j] != grid[high][j]) {
                    ++b;
                }
            }
        }
        return std::min(a, b);
    }
};