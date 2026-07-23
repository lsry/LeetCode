#include <utility>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};

    void update(vector<int> &scores, vector<unsigned long long int> &ways, int rc, int rr) {
        if (rr >= scores.size() || scores[rr] == -1) {
            return;
        }
        if (scores[rr] == scores[rc]) {
            ways[rc] = (ways[rr] + ways[rc]) % MOD;
        } else if (scores[rr] > scores[rc]) {
            scores[rc] = scores[rr];
            ways[rc] = ways[rr];
        }
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int N = board.size();
        vector<unsigned long long int> ways(N, 0);
        ways[N - 1] = 1;
        vector<int> scores(N, -1);
        scores[N - 1] = 0;
        vector<std::pair<int, unsigned long long int>> lastRow(N, std::pair<int, unsigned long long int>());
        for (int i = 0;i < N;++i) {
            lastRow[i].first = -1;
            lastRow[i].second = 0;
        }
        for (int r = N - 1;r >= 0;--r) {
            for (int c = N - 1;c >= 0;--c) {
                if (board[r][c] == 'X') {
                    ways[c] = 0;
                    scores[c] = -1;
                } else {
                    int score = board[r][c] >= '0' && board[r][c] <= '9' ? (board[r][c] - '0') : 0;
                    if (c + 1 < N && lastRow[c + 1].first != -1 && lastRow[c + 1].first == scores[c]) {
                        ways[c] = (ways[c] + lastRow[c + 1].second) % MOD;
                    } else if (c + 1 < N && lastRow[c + 1].first != -1 && lastRow[c + 1].first > scores[c]) {
                        ways[c] = lastRow[c + 1].second;
                        scores[c] = lastRow[c + 1].first;
                    }
                    update(scores, ways, c, c + 1);
                    if (scores[c] != -1) {
                        scores[c] += score;
                    }
                }
            }
            for (int i = 0;i < N;++i) {
                lastRow[i].first = scores[i];
                lastRow[i].second = ways[i];
            }
        }
        return vector<int>{scores[0] == -1 ? 0 : scores[0], static_cast<int>(ways[0])};
    }
};

int main() {
    vector<string> board{"E12","1X1","21S"};
    Solution s;
    s.pathsWithMaxScore(board);
}
