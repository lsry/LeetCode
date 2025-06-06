#include <algorithm>
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int alow = std::max(0, n - 2 * limit), ahigh = std::min(n, limit);      
        long long ans{0};
        for (int i = alow;i <= ahigh;++i) {
            int blow = std::max(0, n - i - limit), bhigh = std::min(n - i, limit);
            ans += bhigh - blow + 1;
        }
        return ans;
    }
};