#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> flags(value, 0);
        for (int num : nums) {
            unsigned long long int id{1ULL * num + 1ULL * value * 10000000};
            flags[id % value]++;
        }      
        int ans{std::numeric_limits<int>::max()};
        for (int i = 0;i < value;++i) {
            ans = std::min(ans, flags[i] * value + i);
        }
        return ans;
    }
};