#include <vector>
using std::vector;

#include <unordered_set>

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        std::size_t N{nums.size()};
        vector<std::unordered_set<int>> nexts(N + 1, std::unordered_set<int>());
        for (vector<int> const &vi : sequences) {
            for (std::size_t i{1};i < vi.size();++i) {
                nexts[vi[i - 1]].insert(vi[i]);
            }
        } 
        for (std::size_t i{1};i < nums.size();++i) {
            if (nexts[nums[i - 1]].find(nums[i]) == nexts[nums[i - 1]].end()) {
                return false;
            }
        }
        return true;
    }
};