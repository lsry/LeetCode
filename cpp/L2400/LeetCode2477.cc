#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
    long long total{0};
    int trace(std::unordered_map<int, vector<int>> &adjoints, int seats, vector<bool> &flags, int node) {
        flags[node] = true;
        int people{0};
        for (int const next : adjoints[node]) {
            if (flags[next]) {
                continue;
            }
            int p1 = trace(adjoints, seats, flags, next);
            if (p1 == 0) {
                continue;
            }
            if (p1 % seats == 0) {
                total += p1 / seats;
            } else {
                total += p1 / seats + 1;
            }
            people += p1;
        }
        return people;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        std::unordered_map<int, vector<int>> adjoints;
        int n{0};
        for (vector<int> const &road : roads) {
            n = std::max(n, std::max(road[0], road[1]));
            adjoints[road[0]].push_back(road[1]);
            adjoints[road[1]].push_back(road[0]);
        }
        vector<bool> flags(n + 1, false);
        trace(adjoints, seats, flags, 0);
        return total;
    }
};