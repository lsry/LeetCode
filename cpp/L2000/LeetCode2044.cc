#include <vector>
using std::vector;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        size = nums.size();
        if (size < 2) {
            return size;
        }
        int mask = 1 << size;
        int count = 0;
        int max = 0;
        for (int i = 1;i < mask;++i) {
            int value = 0;
            for (int j = 0;j < size;++j) {
                if ((i & (1 << j)) != 0) {
                    value |= nums[j];
                }
            }
            if (value == max) {
                ++count;
            } else if (value > max) {
                count = 1;
                max = value;
            }
        } 
        return count;  
    }

private:
    std::size_t size;
};