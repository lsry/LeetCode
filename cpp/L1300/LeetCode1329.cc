#include <vector>
using std::vector;

class Solution {
    void sortByAngle(vector<vector<int>> &mat, int x, int y) {
        int M = mat.size(), N = mat[0].size();
        for (int i = 1;x + i < M && y + i < N;++i) {
            int nx = x + i, ny = y + i;
            int val = mat[nx][ny];
            while (nx - 1 >= 0 && ny - 1 >= 0 && mat[nx - 1][ny - 1] > val) {
                mat[nx][ny] = mat[nx - 1][ny - 1];
                --nx;
                --ny;
            }
            mat[nx][ny] = val;
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        for (int i = 0;i < M;++i) {
            sortByAngle(mat, i, 0);
        }
        for (int j = 1;j < N;++j) {
            sortByAngle(mat, 0, j);
        }
        return mat;
    }
};