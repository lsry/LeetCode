#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) {
            return {};
        }
        vector<vector<int>> ans{{1}};
        if (numRows == 1) {
            return ans;
        }
        for (int r = 1;r < numRows;++r) {
            vector<int> cur{1};
            for (int i = 1;i < r;++i) {
                cur.push_back(ans[r - 1][i - 1] + ans[r - 1][i]);
            }
            cur.push_back(1);
            ans.emplace_back(cur);
        }
        return ans;
    }
};