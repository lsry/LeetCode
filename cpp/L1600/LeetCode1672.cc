#include <vector>
using std::vector;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (const vector<int> &account : accounts) {
            int wealth = 0;
            for (const int i : account) {
                wealth += i;
            }
            maxWealth = std::max(maxWealth, wealth);
        }
        return maxWealth;
    }
};