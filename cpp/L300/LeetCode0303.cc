#include <vector>
using std::vector;

class NumArray {
    vector<int> pres;
public:
    NumArray(vector<int>& nums): pres(nums.size() + 1, 0) {
        for (int i = 1;i <= nums.size();++i) {
            pres[i] = pres[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return pres[right + 1] - pres[left];
    }
};