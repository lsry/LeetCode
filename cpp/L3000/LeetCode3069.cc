#include <vector>
using std::vector;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> s1{nums[0]}, s2{nums[1]};
        for (int i = 2;i < nums.size();++i) {
            if (s1.back() > s2.back()) {
                s1.push_back(nums[i]);
            } else {
                s2.push_back(nums[i]);
            }
        }
        for (int n : s2) {
            s1.push_back(n);
        }
        return s1;
    }
};
