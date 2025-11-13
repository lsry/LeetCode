#include <algorithm>
#include <cstddef>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans{0};
        std::size_t cz{colors.size()};
        for (std::size_t i{0};i < cz; ++i) {
            int cnt{0};
            std::size_t j{i};
            int maxTime{neededTime[i]}, sumTime{0};
            while (j < cz && colors[j] == colors[i]) {
                ++cnt;
                maxTime = std::max(maxTime, neededTime[j]);
                sumTime += neededTime[j];
                ++j;
            }
            if (cnt > 1) {
                ans += sumTime - maxTime;
            }
            i = j - 1;
        }
        return ans;
    }
};
