#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
    int M, N;
    int getSum(vector<vector<int>> const &grid, int x, int y, int dx, int dy) {
        int sum{0};
        for (int a{0};a < 3 && x >= 0 && y >= 0 && x < M && y < N;x += dx, y += dy,++a) {
            sum += grid[x][y];
        }
        return sum;
    }

    bool check(vector<vector<int>> const &grid, int x, int y) {
        std::unordered_set<int> st;
        for (int i = 0;i < 3;++i) {
            for (int j = 0;j < 3;++j) {
                if (grid[x + i][y + j] < 1 || grid[x + i][y + j] > 9) {
                    return false;
                }
                st.insert(grid[x + i][y + j]);
            }
        }
        if (st.size() != 9) {
            return false;
        }
        int s1{getSum(grid, x, y, 0, 1)};
        int s2{getSum(grid, x + 1, y, 0, 1)};
        if (s2 != s1) {
            return false;
        }
        s2 = getSum(grid, x + 2, y, 0, 1);
        if (s2 != s1) {
            return false;
        }
        s2 = getSum(grid, x, y, 1, 0);
        if (s2 != s1) {
            return false;
        }
        s2 = getSum(grid, x, y + 1, 1, 0);
        if (s2 != s1) {
            return false;
        }
        s2 = getSum(grid, x, y + 2, 1, 0);
        if (s2 != s1) {
            return false;
        }
        s2 = getSum(grid, x, y, 1, 1);
        if (s2 != s1) {
            return false;
        }
        s2 = getSum(grid, x, y + 2, 1, -1);
        return s1 == s2;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        M = grid.size(), N = grid[0].size();
        int ans{0};
        for (int i = 0;i < M - 2;++i) {
            for (int j = 0;j < N - 2;++j) {
                if (check(grid, i, j)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
