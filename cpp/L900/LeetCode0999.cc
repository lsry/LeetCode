#include <vector>
using std::vector;

class Solution {
    int hvActive(vector<vector<char>> const &board, int M, int N, int x, int y, int dx, int dy) {
        int ans{0};
        for (int i = 0;;++i) {
            x += dx;
            y += dy;
            if (x < 0 || x >= M || y < 0 || y >= N) {
                break;
            }
            if (board[x][y] == '.') {
                continue;
            }
            if (board[x][y] == 'B') {
                break;
            }
            if (board[x][y] == 'p') {
                ++ans;
                break;
            }
        }
        return ans;
    }
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int M = board.size(), N = board[0].size();
        int ans{0};
        int rx = 0, ry = 0;
        for (int i = 0;i < M;++i) {
            bool find{false};
            for (int j = 0;j < N;++j) {
                if (board[i][j] == 'R') {
                    rx = i;
                    ry = j;
                    find = true;
                    break;
                }
            }
            if (find) {
                break;
            }
        }

        ans += hvActive(board, M, N, rx, ry, -1, 0);
        ans += hvActive(board, M, N, rx, ry, 1, 0);
        ans += hvActive(board, M, N, rx, ry, 0, -1);
        ans += hvActive(board, M, N, rx, ry, 0, 1);
        return ans;
    }
};