#include <vector>
using std::vector;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        int flip{0};
        for (int i = 0;i <= (M - 1) / 2;++i) {
            for (int j = 0;j <= (N - 1) / 2;++j) {
                int curOne{0}, curZero{0};
                int count{1};
                if (grid[i][j] == 1) {
                    ++curOne;
                } else {
                    ++curZero;
                }
                if (M - 1 - i != i) {
                    if (grid[M - 1 - i][j] == 1) {
                        ++curOne;
                    } else {
                        ++curZero;
                    }
                    ++count;
                }
                if (N - 1 - j != j) {
                    if (grid[i][N - 1 - j] == 1) {
                        ++curOne;
                    } else {
                        ++curZero;
                    }
                    ++count;
                }
                if (M - 1 - i != i && N - 1 - j != j) {
                    if (grid[M - 1 - i][N - 1 - j] == 1) {
                        ++curOne;
                    } else {
                        ++curZero;
                    }
                    ++count;
                }
                if (count == 4 && curOne != count && curZero != count) {
                    if (curOne >= curZero) {
                        flip += curZero;
                    } else {
                        flip += curOne;
                    }
                }
            }
        }
        
    }
};