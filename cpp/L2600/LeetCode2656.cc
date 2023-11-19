#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int v{*std::max_element(nums.begin(), nums.end())};
        return k * (v + v + k - 1) / 2;
    }
};