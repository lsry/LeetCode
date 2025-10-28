#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        std::sort(nums.begin(), nums.end());
        int ans{0};
        int N = nums.size();
        if (N < 2) {
            return N;
        }
        std::unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        for (int mi{nums[0]};mi <= nums[N - 1];++mi) {
            auto bt{std::upper_bound(nums.begin(), nums.end(),mi - k - 1)};
            auto et{std::upper_bound(nums.begin(), nums.end(), mi + k)};
            int a = std::min((int)std::distance(bt, et), numOperations + countMap[mi]);
            ans = std::max(ans, a);
        }
        return ans;
    }
};

int main() {
    vector<int> a{88, 53};
    Solution s;
    s.maxFrequency(a, 27, 2);
}
