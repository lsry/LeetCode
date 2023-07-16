#include <vector>
using std::vector;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans{0}, odd{0}, even{0};
        for (int num : nums) {
            long long new_odd = std::max(odd, even + num);
            long long new_even = std::max(even, odd - num);
            ans = std::max(new_even, std::max(ans, new_odd));
            even = new_even;
            odd = new_odd;
        }
        return ans;
    }
};