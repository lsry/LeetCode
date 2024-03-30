#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        std::sort(coins.begin(), coins.end());
        int ans{0}, maxSum{0};
        for (int hope{1}, i{0};hope <= target;) {
            if (i >= coins.size() || hope < coins[i]) {
                ++ans;
                maxSum += hope;
                hope = maxSum + 1;
            } else {
                maxSum += coins[i];
                ++i;
                hope = maxSum + 1;
            }
        }
        return ans;
    }
};