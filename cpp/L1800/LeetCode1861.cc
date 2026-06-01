#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int M = boxGrid.size(), N = boxGrid[0].size();
        vector<vector<char>> arr(N, vector<char>(M, '.'));
        for (int c = 0;c < M;++c) {
            int waitId = N - 1;
            for (int r = N - 1;r >= 0;--r) {
                if (boxGrid[M - 1 -c][r] == '#') {
                    arr[waitId][c] = '#';
                    waitId--;
                } else if (boxGrid[M - 1 - c][r] == '*') {
                    arr[r][c] = '*';
                    waitId = r - 1;
                }
            }
        }
        return arr;
    }
};
