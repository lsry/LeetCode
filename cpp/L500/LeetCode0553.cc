#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res = std::to_string(nums[0]);
        std::size_t sz = nums.size();
        if (sz > 1) {
            res += "/";
        }
        string tmp = sz > 1 ? std::to_string(nums[1]) : "";
        for (std::size_t i = 2;i < sz;++i) {
            tmp += "/" + std::to_string(nums[i]);
        }
        if (sz > 2) {
            tmp = "(" + tmp + ")";
        }
        res += tmp;
        return res;
    }
};