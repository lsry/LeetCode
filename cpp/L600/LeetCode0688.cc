#include <array>
using std::array;
#include <vector>
using std::vector;
#include <queue>
using std::queue;

class SolutionDFSTimeLimitExceed {
private:
    const array<array<int, 2>, 8> dirs = {{{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}}};

    double dfs(vector<vector<double>> &pros, int n, int k, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= n) {
            return 0.0;
        }
        if (k == 0) {
            return 1.0;
        }
        double d = 0.0;
        for (array<int, 2> dir : dirs) {
            d += dfs(pros, n, k - 1, dir[0] + x, dir[1] + y);
        }
        return d / 8;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> pros(n, vector<double>(n));
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                int count = 0;
                for (array<int,2> dir : dirs) {
                    int nx = i + dir[0];
                    int ny = j + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        ++count;
                    }
                }
                pros[i][j] = count * 1.0 / 8;
            }
        }
        return dfs(pros, n, k, row, column);
    }
};

class Solution {
private:
    const array<array<int, 2>, 8> dirs = {{{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}}};

public:
    double knightProbability(int n, int k, int row, int column) {
        if (row >= n || column >= n) {
            return 0.0;
        }
        vector<vector<vector<double>>> memos(k + 1, vector<vector<double>>(n, vector<double>(n)));
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                memos[0][i][j] = 1.0;
            }
        }
        for (int x = 1;x <= k;++x) {
            for (int i = 0;i < n;++i) {
                for (int j = 0;j < n;++j) {
                    double sum = 0.0;
                    for (array<int, 2> dir : dirs) {
                        int nx = dir[0] + i;
                        int ny = dir[1] + j;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            sum += memos[x - 1][nx][ny];
                        }
                    }
                    memos[x][i][j] = sum / 8;
                }
            }
        }
        return memos[k][row][column];
    }
};