#include <algorithm>
#include <vector>
using std::vector;

class Solution {
    /**
     * from min to max
     *        1, 3, 5, 7
     * + 6:   7, 9, 11, 7
     * + 4: 11, 13, 11, 11
     * + 2: 13, 13, 13, 13
     */
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int ans{0};
        int minus{nums[0]};
        for (int i = nums.size() - 1;i > 0;--i) {
            int curMinus = nums[i] + ans;
            ans += curMinus - minus;
            minus = curMinus;
        }
        return ans;
    }
};
