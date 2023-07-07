#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int low{0}, high(numbers.size() - 1);low < high;) {
            int x = numbers[low] + numbers[high];
            if (x == target) {
                return {low + 1, high + 1};
            } else if (x < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {};
    }
};