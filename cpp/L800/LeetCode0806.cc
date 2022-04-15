#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int curWidth = 0;
        int row = 0;
        for (const char c : s) {
            int idx = (int)(c - 'a');
            if (curWidth + widths[idx] > 100) {
                row += 1;
                curWidth = widths[idx];
            } else {
                curWidth += widths[idx];
            }
        }
        vector<int> res;
        res.push_back(curWidth == 0 ? row : row + 1);
        res.push_back(curWidth);
        return res;
    }
};