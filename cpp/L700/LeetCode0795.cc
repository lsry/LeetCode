#include <vector>
using std::vector;
#include <stack>

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans{0};
        int nz = nums.size();
        vector<int> rmax_i(nz, nz);
        std::stack<std::size_t> rt;
        for (int i{nz - 1};i >= 0;--i) {
            while (!rt.empty() && nums[rt.top()] <= nums[i]) {
                rt.pop();
            }
            if (!rt.empty()) {
                rmax_i[i] = rt.top();
            }
            rt.push(i);
        }
        std::stack<int> lt;
        for (int i = 0;i < nz;++i) {
            while (!lt.empty() && nums[lt.top()] < nums[i]) {
                lt.pop();
            }
            int li = lt.empty() ? -1 : lt.top();
            lt.push(i);
            if (nums[i] >= left && nums[i] <= right) {
                ans += (i - li) * (rmax_i[i] - i);
            }
        }
        return ans;
    }
};