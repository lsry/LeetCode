#include <limits>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<std::pair<int, int>>> adjoins(n, vector<std::pair<int, int>>());
        for (vector<int> const &road : roads) {
            adjoins[road[0]].emplace_back(std::pair<int, int>(road[1], road[2]));
            adjoins[road[1]].emplace_back(std::pair<int, int>(road[0], road[2]));
        }
        vector<unsigned long long int> dis(n, std::numeric_limits<unsigned long long int>::max());
        dis[0] = 0ULL;
        vector<unsigned long long int> ways(n, 0ULL);
        ways[0] = 1ULL;
        auto f{[](std::pair<int, unsigned long long int> const &p1, std::pair<int, unsigned long long int> const &p2) {
            return p1.second > p2.second;
        }};
        std::priority_queue<std::pair<int, unsigned long long int>, vector<std::pair<int, unsigned long long int>>, decltype(f)> pq;
        pq.push(std::pair<int, unsigned long long int>(0, 0ULL));
        while (!pq.empty()) {
            auto [u, t] = pq.top();
            pq.pop();
            for (auto const &[v, t2] : adjoins[u]) {
                if (t + t2 < dis[v]) {
                    dis[v] = t + t2;
                    ways[v] = ways[u];
                    pq.emplace(std::pair<int, unsigned long long int>(v, t + t2));
                } else if (t + t2 == dis[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return static_cast<int>(ways[n - 1] % MOD);
    }
};