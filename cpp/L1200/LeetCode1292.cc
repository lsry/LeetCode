#include <vector>
using std::vector;

class Solution {
    int M, N;
    int maxSquareLen(vector<vector<int>> const &preSum, int x, int y, int threshold) {
        int low = 1, high = std::min(M + 2 - x, N + 2 - y);
        while (low < high) {
            int mid = (low + high) / 2;
            int nx = x + mid - 1, ny = y + mid - 1;
            int area = preSum[nx][ny] - preSum[nx][y - 1] - preSum[x - 1][ny] + preSum[x - 1][y - 1];
            if (area <= threshold) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low - 1;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        M = mat.size(), N = mat[0].size();
        vector<vector<int>> preSum(M + 1, vector<int>(N + 1, 0));
        for (int i = 1;i <= M;++i) {
            for (int j = 1;j <= N;++j) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int len{0};
        for (int i = 1;i <= M;++i) {
            for (int j = 1;j <= N;++j) {
                len = std::max(len, maxSquareLen(preSum, i, j, threshold));
            }
        }
        return len;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat{{18,70},{61,1},{25,85},{14,40},{11,96},{97,96},{63,45}};
    s.maxSideLength(mat, 48182);
    return 0;
}
