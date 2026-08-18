#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> bits(101, false);
        int mx{-1}, ix{1001};
        for (int num : nums) {
            mx = std::max(mx, num);
            ix = std::min(ix, num);
            bits[num] = true;
        }
        vector<int> ans{};
        for (int i = ix + 1;i < mx;++i) {
            if (!bits[i]) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
