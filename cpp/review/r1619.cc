#include <vector>
using std::vector;
#include <queue>
#include <array>
#include <algorithm>

class Solution {
    constexpr static std::array<std::array<int, 2>, 8> indics {{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

    int waterArea(vector<vector<int>>& land, int x, int y) {
        int ans{0};
        int M = land.size(), N = land[0].size();
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(x, y));
        land[x][y] = -1;
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            ++ans;
            for (std::array<int, 2> const &index : indics) {
                int nx = index[0] + cx;
                int ny = index[1] + cy;
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && land[nx][ny] == 0) {
                    q.push(std::make_pair(nx, ny));
                    land[nx][ny] = -1;
                }
            }
        }
        return ans;
    }
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        std::vector<int> res;
        int M = land.size(), N = land[0].size();
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (land[i][j] == 0) {
                    res.push_back(waterArea(land, i, j));
                }
            }
        }
        std::stable_sort(res.begin(), res.end());
        return res;
    }
};