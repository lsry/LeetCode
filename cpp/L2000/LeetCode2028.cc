#include <vector>
using std::vector;

#include <numeric>

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int r_sum = std::accumulate(rolls.begin(), rolls.end(), 0);
        int sum = mean * (m + n) - r_sum;
        vector<int> res;
        if (sum <= 0 || sum > n * 6 || n <= 0) {
            return res;
        }
        for (int i = 1;i <= n;++i) {
            for (int j = 6;j >= 1;--j) {
                if (sum - j >= n - i) {
                    res.push_back(j);
                    sum -= j;
                    break;
                }
            }
        }
        return res.size() == n ? res : vector<int>();
    }
};