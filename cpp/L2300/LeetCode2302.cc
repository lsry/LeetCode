#include <vector>
using std::vector;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans{0};
        long long sum{0};
        for (int low{0}, high{0};high < nums.size();++high) {
            sum += nums[high];
            while (low <= high && sum * (high - low + 1) >= k) {
                sum -=nums[low];
                ++low;
            }
            if (sum * (high - low + 1) < k) {
                ans += high - low + 1;
            }
        }
        return ans;
    }
};