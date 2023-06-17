#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans{0};
        std::unordered_map<int, int> map;
        for (int num : nums) {
            map[num] += 1;
        }
        int N = nums.size(), t = 0;
        for (auto &[n1, c1] : map) {
            ans += c1 * t * (N - c1 - t);
            t += c1;
        }
        return ans;
    }
};