#include <queue>
#include <vector>
using std::vector;

class Solution {
    int deleteLeaves( std::vector<std::vector<int>> const &adjoints, std::vector<int> &degrees) {
        vector<int> nexts;
        for (int i = 0;i < degrees.size();++i) {
            if (degrees[i] == 1) {
                nexts.push_back(i);
            }
        }
        for (int next : nexts) {
            degrees[next] -= 1;
            for (int node : adjoints[next]) {
                degrees[node] -= 1;
            }
        }
        return nexts.size();
    }
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int N = coins.size();
        std::vector<std::vector<int>> adjoints(N, vector<int>());
        std::vector<int> degrees(N, 0);
        for (vector<int> const &edge : edges) {
            adjoints[edge[0]].push_back(edge[1]);
            adjoints[edge[1]].push_back(edge[0]);
            degrees[edge[0]] += 1;
            degrees[edge[1]] += 1;
        }
        int node = N;
        std::queue<int> q;
        for (int i = 0;i < N;++i) {
            if (degrees[i] == 1 && coins[i] == 0) {
                degrees[i] -= 1;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            --node;
            for (int next : adjoints[n]) {
                degrees[next] -= 1;
                if (degrees[next] == 1 && coins[next] == 0) {
                    degrees[next] -= 1;
                    q.push(next);
                }
            }
        }
        node -= deleteLeaves(adjoints, degrees);
        node -= deleteLeaves(adjoints, degrees);
        return node <= 0 ? 0 : 2 * (node - 1);
    }
};

int main() {
    vector<int> coins{1,0,1,1,1,0,0,1,1,0,1,1,0,0,0,0};
    vector<vector<int>> edges{{0,1},{1,2},{1,3},{3,4},{3,5},{4,6},{2,7},{7,8},{3,9},{8,10},{8,11},{6,12},{7,13},{11,14},{10,15}};
    Solution s;
    s.collectTheCoins(coins, edges);
}