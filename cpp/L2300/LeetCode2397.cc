#include <algorithm>
#include <bit>
#include <vector>
using std::vector;

class Solution {
    int check(vector<int> const &rList, vector<int> const &tempList) {
        int ans{0};
        for (int i = 0;i < rList.size();++i) {
            if (rList[i] == tempList[i]) {
                ++ans;
            }
        }
        return ans;
    }
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int R = matrix.size(), C = matrix[0].size();
        int N = 1 << C; 
        vector<int> rowOnes(R, 0);
        for (int i = 0;i < R;++i) {
            for (int j = 0;j < C;++j) {
                if (matrix[i][j] == 1) {
                    rowOnes[i] += 1;
                }
            }
        }     
        vector<int> tempRow(R, 0);
        int rowCount{0};
        for (unsigned int i = 1;i < N;++i) {
            if (std::popcount(i) != numSelect) {
                continue;
            }
            for (int j = 0;j < C;++j) {
                if (((i >> j) & 1) == 1) {
                    for (int r = 0;r < R;++r) {
                        if (matrix[r][j] == 1) {
                            tempRow[r] += 1;
                        }
                    }
                }
            }
            rowCount = std::max(rowCount, check(rowOnes, tempRow));
            std::fill(tempRow.begin(), tempRow.end(), 0);
        }
        return rowCount;
    }
};