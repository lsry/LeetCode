#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        std::sort(coins.begin(), coins.end());
        int num{1};
        for (int coin : coins) {
            if (coin <= num) {
                num = coin + num;
            } else {
                break;
            }
        }
        return num;
    }
};