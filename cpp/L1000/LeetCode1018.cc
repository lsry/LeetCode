#include <cstddef>
#include <vector>
using std::vector;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        std::size_t N{nums.size()};
        vector<bool> ans(N, false);
        int last{0};
        for (std::size_t i{0};i < N;++i) {
            last = (last * 2 + nums[i]) % 5;
            ans[i] = last == 0;
        }
        return ans;
    }
};
