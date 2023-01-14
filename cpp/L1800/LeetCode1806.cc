#include <vector>

class Solution {
public:
    int reinitializePermutation(int n) {
        std::vector<bool> flags(n, false);
        int res{0};
        for (int i = 0;i < n;++i) {
            if (!flags[i]) {
                res = std::max(res, search(i, flags, n));
            }
        }
        return res;
    }

    int search(int x, std::vector<bool> &flags, int n) {
        int ans{0};
        while (!flags[x]) {
            ++ans;
            flags[x] = true;
            if (x % 2 == 0) {
                x = x / 2;
            } else {
                x = n / 2 + (x - 1) / 2;
            }
        }
        return ans;
    }
};