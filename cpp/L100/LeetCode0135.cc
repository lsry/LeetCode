#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector<int> count(N, 0);
        count[0] = 1;
        for (int i = 1;i < N;++i) {
            if (ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            } else {
                count[i] = 1;
            }
        }
        int last{1};
        int ans{std::max(last, count[N - 1])};
        for (int i = N - 2;i >= 0;--i) {
            if (ratings[i] > ratings[i + 1]) {
                last++;
            } else {
                last = 1;
            }
            ans += std::max(count[i], last);
        }
        return ans;
    }
};