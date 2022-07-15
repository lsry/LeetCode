#include <vector>
using std::vector;

#include <unordered_map>

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        std::unordered_map<int, int> idxMap;
        int az = arr.size();
        for (int i{0};i < az;++i) {
            idxMap[arr[i]] = i;
        }
        vector<vector<int>> dp(az, vector<int>(az, 0));
        int ans = 0;
        for (int i{0};i < az;++i) {
            for (int j = i - 1;j >= 0;--j) {
                int first = arr[i] - arr[j];
                if (first < arr[j] && idxMap.find(first) != idxMap.end()) {
                    dp[i][j] = std::max(dp[j][idxMap[first]] + 1, 3);
                    ans = std::max(dp[i][j], ans);
                }
            }
        }
        return ans;
    }
};