#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int N = nums.size();
        int ans{0};
        for (int i = 0;i < N;++i) {
            std::unordered_set<int> odd, even;
            for (int j = i;j < N;++j) {
                if (nums[j] % 2 == 0) {
                    even.emplace(nums[j]);
                } else {
                    odd.emplace(nums[j]);
                }
                if (odd.size() == even.size()) {
                    ans = std::max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
