#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
    int digitSum(int num) {
        int ans{0};
        while (num > 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
public:
    int minSwaps(vector<int>& nums) {
        int N = nums.size();
        vector<int> indics(N, 0);
        std::iota(indics.begin(), indics.end(), 0);
        std::sort(indics.begin(), indics.end(), [&](int a, int b) {
            int as = digitSum(nums[a]);
            int bs = digitSum(nums[b]);
            return as == bs ? nums[a] < nums[b] : as < bs;
        });
        vector<int> targetPos(N, 0);
        for (int i = 0;i < N;++i) {
            targetPos[indics[i]] = i;
        }
        vector<bool> visited(N, false);
        int cycles{0};
        for (int i = 0;i < N;++i) {
            if (visited[i]) {
                continue;
            }
            ++cycles;
            for (int j = i;!visited[j];j = targetPos[j]) {
                visited[j] = true;
            }
        }
        return N - cycles;
    }
};
