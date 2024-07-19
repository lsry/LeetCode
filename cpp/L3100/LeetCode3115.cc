#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
    const static std::unordered_set<int> st;
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int low{0}, high = nums.size() - 1;
        while (low < nums.size() && !st.contains(nums[low])) {
            ++low;
        }
        while (high >= 0 && !st.contains(nums[high])) {
            --high;
        }
        return high - low;
    }
};
std::unordered_set<int> const Solution::st = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};