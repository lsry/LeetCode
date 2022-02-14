#include <unordered_map>
using std::unordered_map;

#include <vector>
using std::vector;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> map;
        for (const int &num : nums) {
            int n = k + num;
            count += map[n];
            n = -k + num;
            count += map[n];
            map[num] = map[num] + 1;
        }
        return count;
    }
};