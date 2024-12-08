#include <vector>
using std::vector;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int N = skills.size();
        for (int i = 0, c = k;i < N;) {
            int j = i + 1;
            while (j < N && c > 0 && skills[j] < skills[i]) {
                ++j;
                --c;
            }
            if (j == N || c == 0) {
                return i;
            }
            i = j;
            c = k - 1;
        }
        return -1;
    }
};