#include <vector>
using std::vector;
#include <array>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Solution {
private:
    constexpr static std::array<std::array<int, 2>, 4> indics{{{-1, 0},{0, -1}, {1, 0}, {0, 1}}};
    std::size_t M{0}, N{0};

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& g2, int index, int x, int y) {
        int area = 0;
        std::queue<std::pair<int, int>> q;
        q.push({x, y});
        g2[x][y] = index;
        while (!q.empty()) {
            ++area;
            std::pair<int, int> p = q.front();
            q.pop();
            for (std::array<int, 2> const &indic : indics) {
                int nx = indic[0] + p.first;
                int ny = indic[1] + p.second;
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] == 1 && g2[nx][ny] == 0) {
                    q.push({nx, ny});
                    g2[nx][ny] = index;
                }
            }
        }
        return area;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        M = grid.size();
        if (M == 0) {
            return 0;
        }
        N = grid[0].size();
        if (N == 0) {
            return 0;
        }
        vector<vector<int>> g2(M, vector<int>(N, 0));
        std::unordered_map<int, int> areas;
        int index{2};
        int maxArea{0};
        for (std::size_t i{0};i < M;++i) {
            for (std::size_t j{0};j < N;++j) {
                if (grid[i][j] == 1 && g2[i][j] == 0) {
                    int area = bfs(grid, g2, index, i, j);
                    areas[index] = area;
                    ++index;
                    maxArea = std::max(maxArea, area);
                }
            }
        }
        for (std::size_t i{0};i < M;++i) {
            for (std::size_t j{0};j < N;++j) {
                if (grid[i][j] == 0) {
                    int area = 1;
                    std::unordered_set<int> st;
                    for (std::array<int, 2> const &indic : indics) {
                        int nx = indic[0] + i;
                        int ny = indic[1] + j;
                        if (nx >= 0 && nx < M && ny >= 0 && ny < N && g2[nx][ny] > 0) {
                            int id = g2[nx][ny];
                            if (st.find(id) == st.end()) {
                                area += areas[id];
                                st.emplace(id);
                            }
                        }
                    }
                    maxArea = std::max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};