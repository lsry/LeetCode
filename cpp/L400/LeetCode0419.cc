#include <vector>
using std::vector;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans{0};
        int M = board.size();
        int N = board[0].size();
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (board[i][j] == 'X') {
                    bool flag = (i - 1 >= 0 && board[i - 1][j] == 'X') || (j - 1 >= 0 && board[i][j - 1] == 'X');
                    if (!flag) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};