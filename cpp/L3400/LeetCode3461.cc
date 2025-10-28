#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    bool hasSameDigits(string s) {
        vector<int> nums;
        for (char const c : s) {
            nums.push_back(c - '0');
        }
        int right = nums.size();
        while (right > 2) {
            for (int i = 1;i < right;++i) {
                nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
            }
            --right;
        }
        return right == 2 && nums[0] == nums[1];
    }
};
