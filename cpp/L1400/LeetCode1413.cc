#include <limits>
#include <vector>
using std::vector;
#include <numeric>

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mv = std::numeric_limits<int>::max();
        int sum = 0;
        for (int num : nums) {
            sum += num;
            mv = std::min(mv, sum);
        }
        return mv < 0 ? (1 - mv) : 1;
    }
};