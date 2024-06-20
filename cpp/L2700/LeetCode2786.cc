#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long evenMax{std::numeric_limits<int>::min()}, oddMax{std::numeric_limits<int>::min()};
        if (nums[0] % 2 == 0) {
            evenMax = nums[0];
        } else {
            oddMax = nums[0];
        }
        for (auto it{nums.begin() + 1};it != nums.end();++it) {
            int num = *it;
            if (num % 2 == 0) {
                long long x1 = std::max(evenMax + num, oddMax + num - x);
                evenMax = std::max(evenMax, x1);
            } else {
                long long x1 = std::max(evenMax + num - x, oddMax + num);
                oddMax = std::max(oddMax, x1);
            }
        }
        return std::max(evenMax, oddMax);
    }
};

int main() {
    Solution s;
    vector<int> v{8,50,65,85,8,73,55,50,29,95,5,68,52,79};
    s.maxScore(v, 74);
}