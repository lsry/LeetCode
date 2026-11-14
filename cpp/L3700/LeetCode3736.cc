#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mv = *std::max_element(nums.begin(), nums.end());
        int ans{0};
        for (int n : nums) {
            ans += mv - n;
        }
        return ans;
    }
};
