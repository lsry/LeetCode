#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        std::unordered_map<int, std::vector<int>> map;
        for (int i = 0;i <groupSizes.size();++i) {
            int gc = groupSizes[i];
            if (map[gc].size() == gc) {
                res.push_back(map[gc]);
                map[gc].clear();
            }
            map[gc].push_back(i);
        }
        for (auto &[gc, vi] : map) {
            res.push_back(vi);
        }
        return res;
    }
};