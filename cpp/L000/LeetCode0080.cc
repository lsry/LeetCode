#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        if (N < 3) {
            return N;
        }
        int i = 2;
        for (int j{2};j < N;++j) {
            if (i - 2 >= 0 && nums[i - 2] != nums[j]) {
                nums[i] = nums[j];
                ++i;
            }
        } 
        return i;    
    }
};