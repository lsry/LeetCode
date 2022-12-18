#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long int diff = goal - sum;
        if (diff == 0) {
            return 0;
        } 
        if (diff >= -limit && diff <= limit) {
            return 1;
        }
        if (diff < -limit) {
            return diff % (-limit) == 0 ? diff / (-limit) : diff / (-limit) + 1;
        } else {
            return diff % limit == 0 ? diff / limit : diff / limit + 1;
        }
    }
};