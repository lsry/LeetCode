#include <array>
#include <vector>
using std::vector;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        std::array<int, 101> arr{0};
        for (int num : nums) {
            arr[num] += 1;
        }
        for (int x : arr) {
            if (x > 2) {
                return false;
            }
        }
        return true;
    }
};