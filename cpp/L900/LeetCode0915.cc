#include <vector>
using std::vector;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> rightMax(nums.size(), 0);
        int mv{*nums.rbegin()};
        for (auto it = nums.rbegin(), rt = rightMax.rbegin();it != nums.rend();++it, ++rt) {
            mv = std::min(*it, mv);
            *rt = mv;
        }
        mv = *nums.begin();
        for (auto it = nums.begin(), rt = rightMax.begin();it != nums.end();++it,++rt) {
            mv = std::max(*it, mv);
            if (mv <= *(rt + 1)) {
                return std::distance(nums.begin(), it) + 1;
            } 
        }
        return -1;
    }
};