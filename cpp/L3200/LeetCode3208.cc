#include <vector>
using std::vector;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int N = colors.size();
        int last{1};
        int ans{0};
        for (int i = 1;i < 2 * N - 1;++i) {
            int bi = (i - 1 + N) % N;
            if (colors[bi] != colors[i]) {
                ++last;
            } else {
                last = 1;
            }
            if (last >= k) {
                ++ans;
            }
        }
        return ans;
    }
};