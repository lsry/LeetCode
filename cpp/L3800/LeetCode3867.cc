#include <algorithm>
#include <cstddef>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        std::size_t N = nums.size();
        vector<int> mxs;
        mxs.reserve(N);
        for (int mx{-1}, i = 0;i < N;++i) {
            mx = std::max(nums[i], mx);
            mxs.push_back(std::gcd(mx, nums[i]));
        }
        std::sort(mxs.begin(), mxs.end());
        long long int ans{0LL};
        for (std::size_t low{0}, high{N - 1};low < high;++low,--high) {
            ans += std::gcd(mxs[low], mxs[high]);
        }
        return ans;
    }
};
