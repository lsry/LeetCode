#include <vector>
using std::vector;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int sum{0};
        bool allZero{true};
        for (int num : nums) {
            sum = sum ^ num;
            if (num != 0) {
                allZero = false;
            }
        }
        return allZero ? 0 : (sum == 0 ? nums.size() - 1 : nums.size());
    }
};
