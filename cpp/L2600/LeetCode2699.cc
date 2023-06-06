#include <vector>
using std::vector;
#include <algorithm>
#include <queue>

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        std::vector<std::vector<std::pair<int, int>>> adjoints(n, std::vector<std::pair<int, int>>());
        for (std::vector<int> const &edge : edges) {
            adjoints[edge[0]].push_back(std::make_pair(edge[1], edge[2]));
            adjoints[edge[1]].push_back(std::make_pair(edge[0], edge[2]));
        }
        std::vector<bool> visited(n, false);
    }
};