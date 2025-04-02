#include <vector>
using std::vector;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int N = questions.size();
        vector<long long> ans(N + 1, 0LL);
        for (int i = N - 1;i >= 0;--i) {
            long long int solved = questions[i][0] + (i + questions[i][1] + 1 <= N ? ans[i + questions[i][1] + 1] : 0);
            long long int unsolved = ans[i + 1];
            ans[i] = std::max(solved, unsolved);
        }
        return ans[0];
    }
};