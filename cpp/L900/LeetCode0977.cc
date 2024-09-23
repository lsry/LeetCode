#include <vector>
using std::vector;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int N = nums.size();
        int right = 0;
        while (right < N && nums[right] < 0) {
            ++right;
        }
        int left = right - 1;
        vector<int> res;
        while (right < N || left >= 0) {
            if (right < N && left >= 0) {
                if (nums[right] * nums[right] <= nums[left] * nums[left]) {
                    res.push_back(nums[right] * nums[right]);
                    ++right;
                } else {
                    res.push_back(nums[left] * nums[left]);
                    --left;
                }
            } else if (left >= 0) {
                res.push_back(nums[left] * nums[left]);
                --left;
            } else {
                res.push_back(nums[right] * nums[right]);
                ++right;
            }
        }
        return res;
    }
};