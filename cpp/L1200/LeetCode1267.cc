#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    int countServersSum(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<int> row(M, 0), col(N, 0);
        for (int i = 0;i < M;++i) {
            for (int j{0};j < N;++j) {
                if (grid[i][j] == 1) {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }
        int ans{0};
        for (int i = 0;i < M;++i) {
            for (int j{0};j < N;++j) {
                if (grid[i][j] == 1 &&(col[j] >= 2 || row[i] >= 2)) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    int countServers(vector<vector<int>>& grid) {
        std::unordered_set<int> servers;
        vector<int> curServers;
        int M = grid.size(), N = grid[0].size();
        for (int i = 0;i < M;++i) {
            curServers.clear();
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 1) {
                    curServers.push_back(i * N + j);
                }
            }
            if (curServers.size() > 1) {
                servers.insert(curServers.begin(), curServers.end());
            }
        }
        for (int j = 0;j < N;++j) {
            curServers.clear();
            for (int i = 0;i < M;++i) {
                if (grid[i][j] == 1) {
                    curServers.push_back(i * N + j);
                }
            }
            if (curServers.size() > 1) {
                servers.insert(curServers.begin(), curServers.end());
            }
        }
        return servers.size();
    }
};
