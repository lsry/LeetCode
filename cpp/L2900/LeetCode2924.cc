#include <vector>
using std::vector;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> ins(n, 0);
        for (vector<int> const &edge : edges) {
            ins[edge[1]] += 1;
        }
        int ans{-1};
        for (int i = 0;i < n;++i) {
            if (ins[i] == 0) {
                if (ans != -1) {
                    return -1;
                } else {
                    ans = i;
                }
            }
        }
        return ans;
    }
};