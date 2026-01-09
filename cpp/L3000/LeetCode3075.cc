#include <algorithm>
#include <functional>
#include <vector>
using std::vector;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long int ans{0LL};
        long long int minus{0LL};
        std::sort(happiness.begin(), happiness.end(), std::greater<int>());
        for (int i = 0;i < k;++i) {
            ans += std::max(0LL, happiness[i] - minus);
            ++minus;
        }
        return ans;
    }
};
