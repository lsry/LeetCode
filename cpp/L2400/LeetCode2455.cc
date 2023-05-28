#include <vector>
using std::vector;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum{0}, count{0};
        for (int num : nums) {
            if (num % 6 == 0) {
                sum += num;
                count += 1;
            }
        }      
        return count == 0 ? 0 : sum / count;
    }
};