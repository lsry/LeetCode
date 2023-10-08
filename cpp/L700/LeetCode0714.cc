#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold{std::numeric_limits<int>::min() + 10000000}, unhold{0};
        for (int price : prices) {
            hold = std::max(hold, unhold - price);
            unhold = std::max(unhold, hold + price - fee);
        }
        return std::max(hold, unhold);
    }
};