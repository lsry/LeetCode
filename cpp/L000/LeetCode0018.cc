#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int>> r;
        if (N < 4) {
            return r;
        }
        for (int a{0};a < N - 3;++a) {
            if (a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }
            for (int b{a + 1};b < N - 2;++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }
                for (int c{b + 1}, d{N - 1};c < d;) {
                    long long sum = static_cast<long long>(nums[a]) + nums[b] + nums[c] + nums[d];
                    if (sum < target) {
                        ++c;
                    } else if (sum > target) {
                        --d;
                    } else {
                        int rn = r.size();
                        if (rn == 0 || nums[c] != r[rn - 1][2] || nums[d] != r[rn - 1][3] || nums[a] != r[rn - 1][0] || nums[b] != r[rn - 1][1]) {
                            r.push_back({nums[a], nums[b], nums[c], nums[d]});
                        }
                        ++c;
                        --d;
                    }
                }
            }           
        }
        return r;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> vi{-1,0,-5,-2,-2,-4,0,1,-2};
    s.fourSum(vi, -9);
    return 0;
}
