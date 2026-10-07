#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
    void trace(vector<string> &list, string &path, int left, int right) {
        if (left == 0 && right == 0) {
            list.push_back(path);
            return;
        }
        if (left > 0) {
            path.push_back('(');
            trace(list, path, left - 1, right);
            path.pop_back();
        }
        if (right > left) {
            path.push_back(')');
            trace(list, path, left, right - 1);
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        string r;
        trace(list, r, n, n);
        return list;
    }
};
