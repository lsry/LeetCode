#include <vector>
using std::vector;
#include <numeric>

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int minRound{0};
        int maxProfit{0}, lastProfit{0};
        int count{0};
        int i = 0;
        do {
            if (i < customers.size()) {
                count += customers[i];
            }
            ++i;
            int t = 4;
            if (count >= 4) {
                count -= 4;
            } else {
                t = count;
                count = 0;
            }
            lastProfit = lastProfit + boardingCost * t - runningCost;
            if (lastProfit > maxProfit) {
                maxProfit = lastProfit;
                minRound = i;
            }
        } while (count > 0 || i < customers.size());
        return maxProfit > 0 ? minRound : -1;
    }
};