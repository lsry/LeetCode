#include <vector>
using std::vector;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int totalGoal = 0;
        for (int p : possible) {
            if (p == 0) {
                totalGoal -= 1;
            } else {
                totalGoal += 1;
            }
        }      
        int goalA{possible[0] == 0 ? -1 : 1}, goalB{possible[0] == 0 ? totalGoal + 1 : totalGoal - 1};
        int ans{1};
        for (int i = 1;i < possible.size() && goalA <= goalB;++i) {
            ++ans;
            if (possible[i] == 0) {
                goalA -= 1;
                goalB += 1;
            } else {
                goalA += 1;
                goalB -= 1;
            }
        }
        return goalA <= goalB ? -1 : ans;
    }
};