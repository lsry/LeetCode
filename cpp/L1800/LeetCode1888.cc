#include <array>
#include <string>
#include <vector>
using std::string;

class Solution {
public:
    int minFlips(string s) {
        int N = s.size();
        std::vector<std::array<int, 2>> pre(N + 1, std::array<int, 2>());
        pre[0][0] = 0;
        pre[0][1] = 0;
        for (int i = 1;i <= N;++i) {
            pre[i][0] = pre[i - 1][1] + (s[i - 1] == '0' ? 0 : 1);
            pre[i][1] = pre[i - 1][0] + (s[i - 1] == '1' ? 0 : 1);
        }
        int ans = std::min(pre[N][0], pre[N][1]);
        if (N % 2 == 0) {
            return ans;
        }
        int t0 = 0, t1 = 0;
        for (int i = N - 1;i >= 0;--i) {
            int x = t0;
            t0 = t1 + (s[i] == '0' ? 0 : 1);
            t1 = x + (s[i] == '1' ? 0 : 1);
            ans = std::min(ans, std::min(pre[i][0] + t0, pre[i][1] + t1));
        }
        return ans;
    }
};
