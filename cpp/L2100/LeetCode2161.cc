#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int N = nums.size();
        vector<int> ans(N, pivot);
        int le = -1, la = N;
        int i = 0;
        for (;i < N;++i) {
            if (nums[i] < pivot) {
                ++le;
                ans[le] = nums[i];
            } else if (nums[i] > pivot) {
                --la;
                ans[la] = nums[i];
            }
        }
        std::reverse(ans.begin() + la, ans.end());
        return ans;
    }
};
