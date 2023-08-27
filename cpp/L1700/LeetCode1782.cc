#include <algorithm>
#include <utility>
#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> nodes(n, 0);
        std::unordered_map<int, int> edgeMap;
        for (vector<int> const &edge : edges) {
            int a{edge[0] - 1}, b{edge[1] - 1};
            if (a > b) {
                std::swap(a, b);
            }
            nodes[a] += 1;
            nodes[b] += 1;
            edgeMap[a * n + b] += 1;
        }
        vector<int> sortDegree{nodes};
        std::sort(sortDegree.begin(), sortDegree.end());
        vector<int> ans;
        for (int bound : queries) {
            int total{0};
            for (int i{0};i < n;++i) {
                int j = std::upper_bound(sortDegree.begin() + i + 1, sortDegree.end(), bound - sortDegree[i]) - sortDegree.begin();
                total += n - j;
            }
            for (auto const &[key, value] : edgeMap) {
                int ea{key / n}, eb{key % n};
                if (nodes[ea] + nodes[eb] > bound && nodes[ea] + nodes[eb] - value <= bound) {
                    total -= 1;
                }
            }
            ans.emplace_back(total);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> e{{1,2},{2,4},{1,3},{2,3},{2,1}};
    vector<int> q{2,3};
    Solution s;
    s.countPairs(4, e, q);
}