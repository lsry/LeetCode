#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int profit{0}, min{prices[0]};
        for (auto it{prices.begin() + 1};it != prices.end();++it) {
            if (*it > min) {
                profit = std::max(profit, *it - min);
            } else if (*it < min) {
                min = *it;
            }
        }
        return profit;
    }
};