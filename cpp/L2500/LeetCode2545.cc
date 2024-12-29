#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        std::sort(score.begin(), score.end(), [&](vector<int> const &m1, vector<int> const &m2) {
            return m1[k] > m2[k];
        });      
        return score;
    }
};