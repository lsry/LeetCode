#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num] += 1;
        }
        vector<vector<int>> res;
        for (auto const &[num, count] : counts) {
            for (int i = 0;i < count;++i) {
                if (i < res.size()) {
                    res[i].push_back(num);
                } else {
                    res.push_back(vector<int>());
                    res.back().push_back(num);
                }
            }
        }
        return res;
    }
};