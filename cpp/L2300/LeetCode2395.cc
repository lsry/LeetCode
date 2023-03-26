#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (auto it{nums.begin() + 1};it != nums.end();++it) {
            int s{*it + *(it - 1)};
            if (map[s] > 0) {
                return true;
            }
            map[s] += 1;
        }
        return false;
    }
};