#include <vector>
using std::vector;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0;i < 9;++i) {
            vector<bool> flag(9, false);
            for (int j = 0;j < 9;++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int id{board[i][j] - '1'};
                if (flag[id]) {
                    return false;
                }
                flag[id] = true;
            }
        }
        for (int j = 0;j < 9;++j) {
            vector<bool> flag(9, false);
            for (int i = 0;i < 9;++i) {
                if (board[i][j] == '.') {
                    continue;
                }
                int id{board[i][j] - '1'};
                if (flag[id]) {
                    return false;
                }
                flag[id] = true;
            }
        }
        for (int i = 0;i < 9;i += 3) {
            for (int j = 0;j < 9;j += 3) {
                vector<bool> flag(9, false);
                for (int x = 0;x < 3;++x) {
                    for (int y = 0;y < 3;++y) {
                        char c = board[i + x][j + y];
                        if (c == '.') {
                            continue;
                        }
                        int id{c - '1'};
                        if (flag[id]) {
                            return false;
                        }
                        flag[id] = true;
                    }
                }
            }
        }
        return true;
    }
};