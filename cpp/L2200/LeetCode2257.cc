#include <vector>
using std::vector;

class Solution {
    void toGuard(vector<vector<int>> &board, int x, int y) {
        for (int i = x - 1;i >= 0 && board[i][y] != 1;--i) {
            board[i][y] = 2;
        }
        for (int i = x + 1;i < board.size() && board[i][y] != 1;++i) {
            board[i][y] = 2;
        }
        for (int j = y - 1;j >= 0 && board[x][j] != 1;--j) {
            board[x][j] = 2;
        }
        for (int j = y + 1;j < board[0].size() && board[x][j] != 1;++j) {
            board[x][j] = 2;
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> board(m, vector<int>(n, 0));
        for (vector<int> const &wall : walls) {
            board[wall[0]][wall[1]] = 1;
        }
        for (vector<int> const &guard : guards) {
            board[guard[0]][guard[1]] = 1;
        }
        for (vector<int> const &guard : guards) {
            toGuard(board, guard[0], guard[1]);
        }
        int ans{0};
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                if (board[i][j] == 0) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
