#include <vector>
using std::vector;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int cnt{0};
        for (int i = 0;i < 32;++i) {
            int x{0};
            for (int cand : candidates) {
                if (((cand >> i) & 1) == 1) {
                    ++x;
                }
            }
            cnt = std::max(x, cnt);
        }
        return cnt;
    }
};