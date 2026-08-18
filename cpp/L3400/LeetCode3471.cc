#include <algorithm>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == 1) {
            std::unordered_map<int, int> cntMap;
            for (int n : nums) {
                cntMap[n]++;
            }
            int ans{-1};
            for (auto const &[k, v] : cntMap) {
                if (v == 1) {
                    ans = std::max(ans, k);
                }
            }
            return ans;
        }
        int maxE{nums[0]};
        bool fv{false}, ev{false};
        int N = nums.size();
        for (int i = 0;i < N;++i) {
            maxE = std::max(maxE, nums[i]);
            if (i > 0 && i < N - 1) {
                if (nums[i] == nums[0]) {
                    fv = true;
                }
                if (nums[i] == nums[N - 1]) {
                    ev = true;
                }
            }
        }
        if (k == N) {
            return maxE;
        }
        if (nums[0] == nums[N - 1] || (fv && ev)) {
            return -1;
        }
        if (!fv && !ev) {
            return std::max(nums[0], nums[N - 1]);
        }
        if (fv) {
            return nums[N - 1];
        }
        return nums[0];
    }
};
