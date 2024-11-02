#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        std::sort(rewardValues.begin(), rewardValues.end());
        int mv{rewardValues.back()};
        vector<bool> dp(2 * mv, false);
        dp[0] = true;
        for (int value : rewardValues) {
            for (int k = 2 * value - 1;k >= value;--k) {
                if (dp[k - value]) {
                    dp[k] = true;
                }
            }
        }
        for (int i = dp.size() - 1;i >= 0;--i) {
            if (dp[i]) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> a{1,1,3,3};
    s.maxTotalReward(a);
}