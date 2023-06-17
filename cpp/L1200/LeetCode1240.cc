#include <vector>
using std::vector;
#include <limits>

class Solution {
    int ans;
    int n, m;

    bool available(int r, int c, vector<vector<bool>> &rect, int k) {
        for (int i = 0;i < k;++i) {
            for (int j = 0;j < k;++j) {
                if (rect[r + i][c + j]) {
                    return false;
                }
            }
        }
        return true;
    }

    void fillAll(int r, int c, vector<vector<bool>> &rect, int k, bool val) {
        for (int i = 0;i < k;++i) {
            for (int j = 0;j < k;++j) {
                rect[r + i][c + j] = val;
            }
        }
    }

    void dfs(int r, int c, vector<vector<bool>> &rect, int cnt) {
        if (cnt >= ans) {
            return;
        }
        if (c >= m) {
            return dfs(r + 1, 0, rect, cnt);
        }
        if (r >= n) {
            ans = std::min(ans, cnt);
            return;
        }
        if (rect[r][c]) {
            dfs(r, c + 1, rect, cnt);
            return;
        }
        
        for (int k = std::min(n - r, m - c);k > 0 && available(r, c, rect, k);--k) {
            fillAll(r, c, rect, k, true);
            dfs(r, c + k, rect, cnt + 1);
            fillAll(r, c, rect, k, false);
        }
    }
public:
    int tilingRectangle(int n, int m) {
        ans = std::max(n, m);
        this->n = n;
        this->m = m;
        vector<vector<bool>> rect(n, vector<bool>(m, false));
        dfs(0, 0, rect, 0);
        return ans;
    }
};