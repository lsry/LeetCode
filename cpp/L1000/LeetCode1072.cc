#include <string>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        std::unordered_map<std::string, int> map;
        for (vector<int> const &row : matrix) {
            std::string s(row.size(), '0');
            for (std::size_t i{0};i < row.size();++i) {
                s[i] = row[0] == 0 ? (row[i] == 0 ? '0' : '1') 
                    : (row[i] == 1 ? '0' : '1');
            }
            map[s] += 1;
        }
        int ans{0};
        for (auto const &[s, n] : map) {
            ans = std::max(n, ans);
        }
        return ans;
    }
};