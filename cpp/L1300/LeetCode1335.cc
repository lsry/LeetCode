#include <vector>
using std::vector;
#include <limits>

class Solution {
    int hardPath(vector<int>& jobDifficulty, int low, int high, int d, vector<vector<vector<int>>> &hards) {
        if (low > high) {
            return d <= 0 ? 0 : -1;
        }
        if (d <= 0 || high - low + 1 < d) {
            return -1;
        }
        if (hards[low][high][d] != -2) {
            return hards[low][high][d];
        }
        int hard = 0;
        int res = std::numeric_limits<int>::max();
        for (int i = low;i <= high;++i) {
            hard = std::max(hard, jobDifficulty[i]);
            int nextHard = hardPath(jobDifficulty, i + 1, high, d - 1, hards);
            if (nextHard != -1) {
                res = std::min(hard + nextHard, res);
            }
        }
        hards[low][high][d] = res == std::numeric_limits<int>::max() ? -1 : res;
        return hards[low][high][d];
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int N = jobDifficulty.size();
        if (N < d) {
            return -1;
        }
        vector<vector<vector<int>>> hards(N, vector<vector<int>>(N, vector<int>(d + 1, -2)));
        hards[0][0][0] = -1;
        hardPath(jobDifficulty, 0, N - 1, d, hards);
        return hards[0][N - 1][d];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v{1,1,1};
    int x = s.minDifficulty(v, 3);
    return 0;
}
