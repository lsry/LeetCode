#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
    bool isPalindrome(string const &s, int left, int right) {
        for (;left < right;++left, --right) {
            if (s[left] != s[right]) {
                return false;
            }
        }
        return true;
    }
    void dfs(string const &s, int index, vector<vector<string>> &result, vector<string> &path) {
        if (index >= s.size()) {
            result.emplace_back(vector<string>(path.begin(), path.end()));
        } else {
            for (int i{index};i < s.size();++i) {
                if (isPalindrome(s, index, i)) {
                    path.emplace_back(s.substr(index, i - index + 1));
                    dfs(s, i + 1, result, path);
                    path.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        dfs(s, 0, result, path);
        return result;
    }
};