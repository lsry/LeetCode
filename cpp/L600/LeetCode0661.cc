#include <vector>
using std::vector;
#include <array>

class Solution {
    std::array<std::array<int, 2>, 9> indics = {{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int M = img.size(), N = img[0].size();
        vector<vector<int>> res(M, vector<int>(N, 0));
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                int sum{0}, count{0};
                for (std::array<int, 2> const &idx : indics) {
                    int nx{i + idx[0]}, ny{j + idx[1]};
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                        ++count;
                        sum += img[nx][ny];
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};