#include <vector>
using std::vector;

#include <unordered_set>

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        std::unordered_set<int> set;
        for (vector<int> &mine : mines) {
            set.emplace(mine[0] * n + mine[1]);
        }
        vector<int> single(n, 0);
        vector<vector<int>> orders(n, vector<int>(n, n + 1));
        // top
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (set.find(i * n + j) != set.end()) {
                    single[j] = 0;
                    orders[i][j] = 0;
                } else {
                    single[j] = single[j] + 1;
                    orders[i][j] = std::min(orders[i][j], single[j]);
                }
            }
        }
        // bottom
        std::fill(single.begin(), single.end(), 0);
        for (int i = n - 1;i >= 0;--i) {
            for (int j = 0;j < n;j++) {
                if (set.find(i * n + j) != set.end()) {
                    single[j] = 0;
                    orders[i][j] = 0;
                } else {
                    single[j] = single[j] + 1;
                    orders[i][j] = std::min(orders[i][j], single[j]);
                }
            }
        }
        // left
        std::fill(single.begin(), single.end(), 0);
        for (int j = 0;j < n;++j) {
            for (int i = 0;i < n;++i) {
                if (set.find(i * n + j) != set.end()) {
                    single[i] = 0;
                    orders[i][j] = 0;
                } else {
                    single[i] = single[i] + 1;
                    orders[i][j] = std::min(orders[i][j], single[i]);
                }
            }
        }
        // right
        std::fill(single.begin(), single.end(), 0);
        for (int j = n - 1;j >= 0;--j) {
            for (int i = 0;i < n;++i) {
                if (set.find(i * n + j) != set.end()) {
                    single[i] = 0;
                    orders[i][j] = 0;
                } else {
                    single[i] = single[i] + 1;
                    orders[i][j] = std::min(orders[i][j], single[i]);
                }
            }
        }
        int order{0};
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                order = std::max(order, orders[i][j]);
            }
        }
        return order;
    }
};