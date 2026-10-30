#include <string>
using std::string;
#include <vector>
using std::vector;
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        ans.reserve(m);
        for (int i = 0;i < m;++i) {
            ans.emplace_back(string(n, '#'));
        }
        for (int j = 0;j < n;++j) {
            ans[0][j] = '.';
        }
        for (int i = 0;i < m;++i) {
            ans[i][n - 1] = '.';
        }
        return ans;
    }
};
