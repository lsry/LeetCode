#include <vector>
using std::vector;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, 0);
        int maxOr{0};
        for (int num : nums) {
            maxOr |= num;
        }
        
    }
};