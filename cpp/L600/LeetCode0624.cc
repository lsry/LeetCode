#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        std::sort(arrays.begin(), arrays.end(), [](vector<int> const &a1, vector<int> const &a2) {
            return a1[0] == a2[0] ? a1[a1.size() - 1] < a2[a2.size() - 1] : a1[0] < a2[0];
        });
        int maxId{0};
        for (int i = 0;i < arrays.size();++i) {
            if (arrays[i][arrays[i].size() - 1] >= arrays[maxId][arrays[maxId].size() - 1]) {
                maxId = i;
            }
        }
        int v1 = arrays[0][arrays[0].size() - 1] - arrays[1][0];
        maxId = maxId == 0 ? arrays.size() - 1 : maxId;
        int v2 = arrays[maxId][arrays[maxId].size() - 1] - arrays[0][0];
        return std::max(v1, v2);
    }
};