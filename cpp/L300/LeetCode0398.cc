#include <vector>
using std::vector;

#include <random>

class Solution {
public:
    Solution(vector<int>& nums) : engine(1), nums(nums) {}
    
    int pick(int target) {
        int ans = 0;
        int count = 0;
        int sz = nums.size();
        for (int i = 0;i < sz;++i) {
            if (nums[i] == target) {
                std::uniform_int_distribution<int> u(0, count);
                if (u(engine) == 0) {
                    ans = i;
                }
                ++count;
            }
        }
        return ans;
    }

private:
    std::default_random_engine engine;
    vector<int> &nums;
};