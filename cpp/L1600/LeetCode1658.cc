#include <vector>
using std::vector;
#include <unordered_map>
#include <numeric>

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        std::unordered_map<int, int> map;
        int sum{std::accumulate(nums.begin(), nums.end(), 0)};
        if (sum < x) {
            return -1;
        }
        if (x == 0) {
            return 0;
        }
        int nz = nums.size();
        if (sum == x) {
            return nz;
        }
        int pre{0};
        map[0] = -1;
        int goal{sum - x};
        int ans = -1;
        for (int i = 0;i < nz;++i) {
            pre += nums[i];
            int gt = pre - goal;
            if (map.find(gt) != map.end()) {
                int ti = map[gt];
                int ni = ti + 1 + nz - i - 1;
                if (ans == -1 || ans > ni) {
                    ans = ni;
                }
            }
            if (map.find(pre) == map.end()) {
                map[pre] = i;
            }
        }
        return ans;
    }
};