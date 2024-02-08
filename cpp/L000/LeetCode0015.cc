#include <vector>
using std::vector;
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nz = nums.size();
        if (nz < 3) {
            return {};
        }
        auto hash{[](vector<int> const &v) {
            int x{0};
            for (int vi : v) {
                x = x * 31 + vi;
            }
            return x;
        }};
        auto eq{[](vector<int> const &v1, vector<int> const &v2) {
            for (int i = 0;i < v1.size();++i) {
                if (v1[i] != v2[i]) {
                    return false;
                }
            }
            return true;
        }};
        std::unordered_set<vector<int>, decltype(hash), decltype(eq)> rst(nz / 3, hash, eq);
        std::sort(nums.begin(), nums.end());
        for (int i{0};i < nz - 2 && nums[i] <= 0;++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            std::unordered_set<int> st;
            for (int j{i + 1};j < nz;++j) {
                auto it{st.find(0 - nums[i] - nums[j])};
                if (it != st.end()) {
                   rst.emplace(vector<int>{nums[i], 0 - nums[i] - nums[j], nums[j]});
                }
                st.emplace(nums[j]);
            }
        }
        return vector<vector<int>>(rst.begin(), rst.end());
    }
};