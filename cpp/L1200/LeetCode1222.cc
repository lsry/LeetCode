#include <algorithm>
#include <array>
#include <vector>
using std::vector;

class Solution {
    void search(std::array<std::array<bool, 8>, 8> const &graphs, vector<int>& king, int dx, int dy, vector<vector<int>> &res) {
        for (int x{king[0] + dx}, y{king[1] + dy};x >= 0 && x < 8 && y >= 0 && y < 8;x += dx, y += dy) {
            if (graphs[x][y]) {
                res.push_back({x, y});
                break;
            }
        }
    }
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        std::array<std::array<bool, 8>, 8> graphs{};
        for (vector<int> const &q : queens) {
            graphs[q[0]][q[1]] = true;
        }
        vector<vector<int>> res;
        search(graphs, king, -1, -1, res);
        search(graphs, king, -1, 0, res);
        search(graphs, king, -1, 1, res);
        search(graphs, king, 0, -1, res);
        search(graphs, king, 0, 1, res);
        search(graphs, king, 1, -1, res);
        search(graphs, king, 1, 0, res);
        search(graphs, king, 1, 1, res);
        return res;
    }
};