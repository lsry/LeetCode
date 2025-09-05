#include <algorithm>
#include <functional>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        for (int i = 0;i < M;++i) {
            vector<int> v;
            for (int x = i, y = 0;x < M && y < N;++x, ++y) {
                v.push_back(grid[x][y]);
            }
            std::sort(v.begin(), v.end(), std::greater<int>());
            for (int x = i, y = 0, j = 0;x < M && y < N;++x, ++y, ++j) {
                grid[x][y] = v[j];
            }
        }
        for (int j = 1;j < N;++j) {
            vector<int> v;
            for (int x = 0, y = j;x < M && y < N;++x, ++y) {
                v.push_back(grid[x][y]);
            }
            std::sort(v.begin(), v.end());
            for (int x = 0, y = j, k = 0;x < M && y < N;++x, ++y, ++k) {
                grid[x][y] = v[k];
            }
        }
        return grid;
    }
};