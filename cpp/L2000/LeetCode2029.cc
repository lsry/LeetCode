#include <vector>
using std::vector;

class Solution {
    bool trace(vector<int> &counts, int preSum) {

    }
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> counts(3, 0);
        for (int s : stones) {
            counts[s % 3]++;
        }

    }
};
