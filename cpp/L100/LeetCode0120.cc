#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }
        int N = triangle.size();
        for (int i = 1;i < N;++i) {
            int M = triangle[i].size();
            for (int j = 0;j < M;++j) {
                int value{std::numeric_limits<int>::max()};
                if (j - 1 >= 0) {
                    value = std::min(value, triangle[i][j] + triangle[i - 1][j - 1]);
                }
                if (j < triangle[i - 1].size()) {
                    value = std::min(value, triangle[i][j] + triangle[i - 1][j]);
                }
                triangle[i][j] = value;
            }
        }   
        return *std::min_element(triangle[N - 1].begin(), triangle[N - 1].end());   
    }
};