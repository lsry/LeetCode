#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int N{0};
        for (int x : count) {
            N += x;
        }
        vector<double> ans(5, 0.0);
        if (N == 0) {
            return ans;
        }
        ans[0] = 255.0;
        for (int i = 0;i < 256;++i) {
            if (count[i] > 0) {
                ans[0] = i;
                break;
            }
        }
        for (int i = 255;i >= 0;--i) {
            if (count[i] > 0) {
                ans[1] = i;
                break;
            }
        }
        int last = 0;
        for (int i = 0;i < 256;++i) {
            if (count[i] > 0) {
                ans[2] += i * 1.0 * count[i] / N;
                if (count[i] > count[last]) {
                    last = i;
                    ans[4] = i;
                }
            }
        }
        last = 0;
        for (int i = 0;i < 256;++i) {
            last += count[i];
            if (last == N / 2) {
                int j = i + 1;
                while (j < 256 && count[j] == 0) {
                    ++j;
                }
                ans[3] = N % 2 == 0 ? (i + j) * 0.5 : j;
                break;
            } else if (last > N / 2) {
                ans[3] = i;
                break;
            }
        }
        return ans;
    }
};