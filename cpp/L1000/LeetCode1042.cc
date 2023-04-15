#include <vector>
using std::vector;

class Solution {
    int selectColor(int flag) {
        for (int i = 1;i <= 4;++i) {
            if ((flag & (1 << i)) == 0) {
                return i;
            }
        }
        return 0;
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<vector<int>>> edges(n, vector<vector<int>>(2, vector<int>()));
        for (vector<int> const &path : paths) {
            edges[path[0] - 1][0].push_back(path[1] - 1);
            edges[path[1] - 1][1].push_back(path[0] - 1);
        }
        vector<int> flags(n, 0);
        vector<int> res(n, 0);
        for (int i = 0;i < n;++i) {
            res[i] = selectColor(flags[i]);
            for (int node : edges[i][0]) {
                flags[node] |= (1 << res[i]);
            }
            for (int node : edges[i][1]) {
                flags[node] |= (1 << res[i]);
            }
        }
        return res;
    }
};