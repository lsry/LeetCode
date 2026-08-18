#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans{0};
        std::unordered_map<int, int> countMap;
        int N = nums.size();
        for (int low{0}, high{0};high < N;++high) {
            countMap[nums[high]] += 1;
            while (low < high && countMap[nums[high]] > k) {
                countMap[nums[low]] -= 1;
                ++low;
            }
            ans = std::max(ans, high - low + 1);
        }
        return ans;
    }
};
