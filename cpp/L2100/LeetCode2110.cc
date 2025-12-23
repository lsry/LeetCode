#include <vector>
using std::vector;
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans{0LL};
        int N = prices.size();
        for (int i = 0;i < N;) {
            int j{i};
            while (j + 1 < N && prices[j] - prices[j + 1] == 1) {
                ++j;
            }
            long long int len = j - i + 1;
            ans += len * (len + 1) / 2LL;
            i = j + 1;
        }
        return ans;
    }
};
