#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        std::size_t sz{s.size()}, qz{queries.size()};
        vector<vector<int>> counts(sz + 1, vector<int>(26, 0));
        for (std::size_t i{1};i <= sz;++i) {
            int cid{s[i - 1] - 'a'};
            for (int j{0};j < 26;++j) {
                if (j != cid) {
                    counts[i][j] = counts[i - 1][j];
                } else {
                    counts[i][j] = counts[i - 1][j] + 1;
                }
            }
        }
        vector<bool> res(qz, false);
        for (std::size_t i{0};i < qz;++i) {
            int odd{0};
            for (int j{0};j < 26;++j) {
                if ((counts[queries[i][1] + 1][j] - counts[queries[i][0]][j]) % 2 != 0) {
                    ++odd;
                }
            }
            if (queries[i][2] >= odd / 2) {
                res[i] = true;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    string str{"abcda"};
    vector<vector<int>> q{{1,2,0}};
    Solution s;
    s.canMakePaliQueries(str, q);
    return 0;
}
