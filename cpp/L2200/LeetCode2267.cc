#include <vector>
using std::vector;

class Solution {
    int M, N;
    bool trace(vector<vector<char>> const &grid, int x, int y, vector<char> &st) {
        if (x < 0 || x >= M || y < 0 || y >= N || (grid[x][y] == ')' && st.empty())) {
            return false;
        }
        if (grid[x][y] == '(') {
            st.push_back('(');
        } else {
            st.pop_back();
        }
        bool result{(x == M - 1 && y == N - 1 && st.empty()) ||
            (x + 1 < M && trace(grid, x + 1, y, st)) || (y + 1 < N && trace(grid, x, y + 1, st))};
        if (grid[x][y] == '(') {
            st.pop_back();
        } else {
            st.push_back('(');
        }
        return result;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        vector<char> st;
        M = grid.size(), N = grid[0].size();
        return trace(grid, 0, 0, st);
    }
};
