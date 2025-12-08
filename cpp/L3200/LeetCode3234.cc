#include <string>
#include <vector>
using std::string;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int N = s.size();
        std::vector<int> pre(N + 1, 0);
        pre[0] = -1;
        int last = 0;
        for (int i = 1;i <= N;++i) {
            pre[i] = last;
            if (s[i - 1] == '0') {
                last = i;
            }
        }
        int ans{0};
        for (int j = 1;j <= N;++j) {
            int i{j};
            int cnt0{s[j - 1] == '0' ? 1 : 0};
            while (i > 0 && cnt0 * cnt0 < N) {
                int cnt1 = j - pre[i] - cnt0;
                if (cnt1 >= cnt0 * cnt0) {
                    ans += std::min(i - pre[i], cnt1 - cnt0 * cnt0 + 1);
                }
                i = pre[i];
                ++cnt0;
            }
        }
        return ans;
    }
};
