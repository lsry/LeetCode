#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold{0},  selt{std::numeric_limits<int>::min()};
        for (int price : prices) {
            sold = std::max(sold, selt + price);
            selt = std::max(selt, sold - price);
        }
        return std::max(selt, sold);
    }
};