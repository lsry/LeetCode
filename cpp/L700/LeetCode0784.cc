#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
private:
    std::size_t sz{0};
    void dfs(string &s, std::size_t pos, vector<string> &strs) {
        if (pos >= sz) {
            strs.push_back(s);
            return;
        }
        dfs(s, pos + 1, strs);
        if (s[pos] >= 'a' && s[pos] <= 'z') {
            s[pos] -= 32;
            dfs(s, pos + 1, strs);
            s[pos] += 32;
        } else if (s[pos] >= 'A' && s[pos] <= 'Z') {
            s[pos] += 32;
            dfs(s, pos + 1, strs);
            s[pos] -= 32;
        } 
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        sz = s.size();
        dfs(s, 0, res);
        return res;
    }
};