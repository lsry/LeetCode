#include <algorithm>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<std::pair<int, int>> vi;
        for (int i = 0;i < nums.size();++i) {
            vi.emplace_back(std::pair<int, int>(nums[i], i));
        }
        std::sort(vi.begin(), vi.end());
        vector<int> ans(nums.size());
        for (int i = 0;i < vi.size();) {
            vector<int> values, indics;
            int j = i;
            for (;j < vi.size() && (j == i || vi[j].first - vi[j - 1].first <= limit);++j) {
                values.push_back(vi[j].first);
                indics.push_back(vi[j].second);
            }
            std::sort(indics.begin(), indics.end());
            for (int k = 0;k < values.size();++k) {
                ans[indics[k]] = values[k];
            }
            i = j;
        }
        return ans;
    }
};
