#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        std::unordered_map<int, int> powerCount;
        for (int p : power) {
            powerCount[p] += 1;
        }
        vector<std::pair<int, int>> powers;
        for (auto const &[k, v] : powerCount) {
            powers.emplace_back(std::pair<int, int>(k, v));
        }
        std::sort(powers.begin(), powers.end(), [](std::pair<int, int> const &p1, std::pair<int, int> const &p2) {
            return p1.first < p2.first;
        });
        vector<long long int> dp(powers.size(), 0LL);
        long long int leftMaxHit{0LL};
        long long int ans{0LL};
        for (int index{-1}, i{0};i < powers.size();++i) {
            while (index + 1 >= 0 && index + 1 < i && powers[index + 1].first + 2 < powers[i].first) {
                leftMaxHit = std::max(leftMaxHit, dp[index + 1]);
                ++index;
            }
            dp[i] = 1LL * powers[i].first * powers[i].second + leftMaxHit;
            ans = std::max(dp[i], ans);
        }
        return ans;
    }
};