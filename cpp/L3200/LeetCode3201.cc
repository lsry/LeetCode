#include <vector>
using std::vector;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int N = nums.size();
        if (nums.empty()) {
            return 0;
        }
        int odd{0}, even{0};
        for (int num : nums) {
            if (num % 2 == 0) {
                ++even;
            } else {
                ++odd;
            }
        }      
        int ans{0};
        for (int i = 0;i < N;) {
            ++ans;
            int j = i;
            while (j < N && nums[j] % 2 == nums[i] % 2) {
                ++j;
            }
            i = j;
        }
        return std::max(ans, std::max(even, odd));
    }
};