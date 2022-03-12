#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vcs(numRows, "");
        std::size_t sz = s.size();
        int row = 0;
        bool add = true;
        for (std::size_t i = 0;i < sz;++i) {
            vcs[row] += s[i];
            nextRow(row, numRows, add);
        }
        string res;
        for (string x : vcs) {
            res += x;
        }
        return res;
    }

private:
    void nextRow(int &row, int nr, bool &add) {
        row = add ? row + 1 : row - 1;
        if (row < 0) {
            row = 1;
            add = true;
        } else if (row >= nr) {
            row = nr - 2;
            add = false;
        }
        if (row >= nr || row < 0) {
            row = 0;
        }
    }
};