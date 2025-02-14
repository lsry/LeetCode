#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> martix(n, vector<int>(n, 0));
        for (int i = 0, num{1};i <= n / 2;++i) {
            for (int j = i;j < n - i;++j) {
                martix[i][j] = num;
                ++num;
            }
            for (int j = i + 1;j < n - i;++j) {
                martix[j][n - i - 1] = num;
                ++num;
            }
            for (int j = n - i - 2;j >= i;--j) {
                martix[n - i - 1][j] = num;
                ++num;
            }
            for (int j = n - i - 2;j > i;--j) {
                martix[j][i] = num;
                ++num;
            }
        }
        return martix;
    }
};