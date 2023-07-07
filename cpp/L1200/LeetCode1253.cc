#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> r(2, vector<int>(colsum.size(), 0));
        for (int i = 0;i < colsum.size();++i) {
            if (colsum[i] == 1) {
                if (upper == 0 && lower == 0) {
                    return {};
                }
                if (upper >= lower) {
                    r[0][i] = 1;
                    upper -= 1;
                } else {
                    r[1][i] = 1;
                    lower -= 1;
                }
            } else if (colsum[i] == 2) {
                if (upper < 1 || lower < 1) {
                    return {};
                }
                r[0][i] = 1;
                r[1][i] = 1;
                lower -= 1;
                upper -= 1;
            }
        }
        return upper == 0 && lower == 0 ? r : vector<vector<int>>();
    }
};