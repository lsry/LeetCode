#include <vector>
using std::vector;

#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        std::unordered_map<int, int> map;
        for (vector<int> const &item : items1) {
            map[item[0]] += item[1];
        }
        for (vector<int> const item : items2) {
            map[item[0]] += item[1];
        }
        vector<vector<int>> res;
        for (auto &[v, w] : map) {
            res.push_back({v, w});
        }
        std::sort(res.begin(), res.end(), [](vector<int> &v1, vector<int> &v2) {
            return v1[0] <= v2[0];
        });
        return res;
    }
};