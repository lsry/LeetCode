#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
    int M, N;

    bool checkBlack(vector<string> &chessBoard, int x, int y, int dx, int dy) {
        while (x >= 0 && x < M && y >= 0 && y < N) {
            if (chessBoard[x][y] == 'X') {
                return true;
            }
            if (chessBoard[x][y] == '.') {
                break;
            }
            x = x + dx;
            y = y + dy;
        }
        return false;
    }

    int flipWhiteCount(vector<string> &chessBoard, vector<std::pair<int, int>> const &whites) {
        int W = whites.size();
        int count{0};
        for (int i = 0;i < W;++i) {
            int curCount{0};
            for (auto &[x, y] : whites) {
                if (chessBoard[x][y] == 'O') {
                    bool f = checkBlack(chessBoard, x, y, -1, -1) && checkBlack(chessBoard, x, y, 1, 1)
                    || checkBlack(chessBoard, x, y, -1, 0) && checkBlack(chessBoard, x, y, 1, 0)
                    || checkBlack(chessBoard, x, y, -1, 1) && checkBlack(chessBoard, x, y, 1, -1)
                    || checkBlack(chessBoard, x, y, 0, -1) && checkBlack(chessBoard, x, y, 0, 1);
                    if (f) {
                        curCount += 1;
                        chessBoard[x][y] = 'X';
                    }
                }
            }
            if (curCount == 0) {
                break;
            }
            count += curCount;
        }
        return count;
    }

    void reset(vector<string> &chessBoard, vector<std::pair<int, int>> const &whites) {
        for (auto &[x, y] : whites) {
            chessBoard[x][y] = 'O';
        }
    }
public:
    int flipChess(vector<string>& chessboard) {
        vector<std::pair<int, int>> whites;
        M = chessboard.size(), N = chessboard[0].size();
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (chessboard[i][j] == 'O') {
                    whites.push_back(std::make_pair(i, j));
                }
            }
        }
        int ans{0};
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (chessboard[i][j] == '.') {
                    chessboard[i][j] = 'X';
                    ans = std::max(ans, flipWhiteCount(chessboard, whites));
                    reset(chessboard, whites);
                    chessboard[i][j] = '.';
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    vector<string> c{"....X.","....X.","XOOO..","......","......"};
    Solution s;
    s.flipChess(c);
    return 0;
}
