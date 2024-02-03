#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        vector<int> nums2(nums.begin(), nums.end());
        std::size_t N{nums.size()};
        long long ans{std::accumulate(nums.begin(), nums.end(), 0LL)};
        for (std::size_t i{1};i < N;++i) {
            for (std::size_t j{0};j < N;++j) {
                nums2[j] = std::min(nums2[j], nums[(j + i) % N]);
            }
            ans = std::min(ans, static_cast<long long>(i) * x + std::accumulate(nums2.begin(), nums2.end(), 0LL));
        }
        return ans;
    }
};

int main() {
    vector<int> a{1, 2, 3};
    Solution s;
    s.minCost(a, 4);
}