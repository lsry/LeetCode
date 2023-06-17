#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
#include <array>

class Solution {
    int f(string const &s) {
        std::array<int, 26> cs{{0}};
        for (char c : s) {
            cs[c - 'a'] += 1;
        }
        for (int x : cs) {
            if (x > 0) {
                return x;
            }
        }
        return 0;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        std::array<int, 11> wfs{{0}};
        for (string const &word : words) {
            int fq{f(word)};
            wfs[fq] += 1;
        }
        for (int i = 9;i >= 0;--i) {
            wfs[i] = wfs[i] + wfs[i + 1];
        }
        vector<int> ans(queries.size(), 0);
        for (int i = 0;i < queries.size();++i) {
            int fq = f(queries[i]);
            if (fq < 10) {
                ans[i] = wfs[fq + 1];
            }
        }
        return ans;
    }
};