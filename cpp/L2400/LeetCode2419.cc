#include <vector>
using std::vector;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans{0}, lastValue{-1}, value{-1};
        int curLen{0};
        for (int num : nums) {
            if (num == value) {
                ++curLen;
            } else {
                value = num;
                curLen = 1;
            }
            if (value > lastValue) {
                lastValue = value;
                ans = curLen;
            } else if (value == lastValue) {
                ans = std::max(curLen, ans);
            }
        }
        return ans;
    }
};