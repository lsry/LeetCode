#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
    int M, N;

    int differentNumber(vector<vector<int>> const &grid, int x, int y, int dx, int dy) {
        std::unordered_set<int> st;
        for (int i = x + dx, j = y + dy;i >= 0 && i < M && j >= 0 && j < N;i += dx, j += dy) {
            st.emplace(grid[i][j]);
        }
        return st.size();
    }
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        vector<vector<int>> answer(M, vector<int>(N, 0));
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                int leftNum = differentNumber(grid, i, j, -1, -1);
                int rightNum = differentNumber(grid, i, j, 1, 1);
                int t = leftNum >= rightNum ? leftNum - rightNum : rightNum - leftNum;
                answer[i][j] = t;
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    vector<vector<int>> x{{1,2,3},{3,1,5},{3,2,1}};
    s.differenceOfDistinctValues(x);
}