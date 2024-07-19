#include <vector>
using std::vector;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans{0LL};
        int N = nums.size();
        for (int i{0};i < N;) {
            int j{i + 1};
            while (j < N && nums[j] != nums[j - 1]) {
                ++j;
            }
            long long ln{j - i};
            ans += ln * (ln + 1) / 2;
            i = j;
        } 
        return ans;     
    }
};