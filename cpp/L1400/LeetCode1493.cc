#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size();
        int ans{0};
        bool zero{false};
        for (int i = 0;i < N;++i) {
            if (nums[i] == 0) {
                zero = true;
                continue;
            }
            int j = i;
            while (j < N && nums[j] == 1) {
                ++j;
            }
            int lenA = j - i;
            if (j + 1 < N && nums[j + 1] == 1) {
                int k = j + 1;
                while (k < N && nums[k] == 1) {
                    ++k;
                }
                int lenB = k - j - 1;
                ans = std::max(ans, lenA + lenB);
            } else {
                ans = std::max(ans, lenA);
            }
            i = j - 1;
        }
        return zero ? ans : ans - 1;
    }
};