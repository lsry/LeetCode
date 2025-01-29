#include <vector>
using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return {1};
        } else if (rowIndex == 1) {
            return {1, 1};
        }
        vector<int> res(rowIndex + 1, 1);
        for (int i = 2;i <= rowIndex;++i) {
            int t = res[0];
            for (int j = 1;j < i;++j) {
                int c = res[j];
                res[j] += t;
                t = c;
            }
        }
        return res;
    }
};