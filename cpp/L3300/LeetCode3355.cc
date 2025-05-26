#include <vector>
using std::vector;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        vector<int> diff(N + 1, 0);
        for (vector<int> const &q : queries) {
            diff[q[0]] += 1;
            diff[q[1] + 1] -= 1;
        }
        for (int sum{0}, i = 0;i < N;++i) {
            sum += diff[i];
            if (sum < nums[i]) {
                return false;
            }
        }
        return true;
    }
};