#include <string>
using std::string;

class Solution {
    void appendPath(string &path, int count, char c) {
        for (int i = 0;i < count;++i) {
            path.push_back(c);
        }
    }
public:
    string alphabetBoardPath(string target) {
        string res;
        int x{0}, y{0};
        for (char c : target) {
            int t{c - 'a'};
            int row{(t / 5) - x}, col{(t % 5) - y};
            x = t / 5, y = t % 5;
            if (col < 0) {
                appendPath(res, -col, 'L');
                appendPath(res, row < 0 ? -row : row, row < 0 ? 'U' : 'D');
            } else if (row < 0) {
                appendPath(res, -row, 'U');
                appendPath(res, col, 'R');
            } else {
                appendPath(res, row, 'D');
                appendPath(res, col, 'R');
            }
            res.push_back('!');
        }
        return res;
    }
};