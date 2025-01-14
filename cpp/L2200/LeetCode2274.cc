#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int sz = special.size();
        if (sz == 0) {
            return top - bottom + 1;
        }
        std::sort(special.begin(), special.end());
        int ans{0};
        for (int i = 0;i <= sz;++i) {
            if (i == 0) {
                ans = std::max(ans, special[i] - bottom);
            } else if (i == sz) {
                ans = std::max(ans, top - special[sz - 1]);
            } else {
                ans = std::max(ans, special[i] - special[i - 1] - 1);
            }
        }
        return ans;
    }
};