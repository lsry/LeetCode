#include <algorithm>
#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        int h0{0}, lastH{0};
        for (int curH : horizontalCuts) {
            h0 = std::max(h0, curH - lastH);
            lastH = curH;
        }
        if (lastH < h) {
            h0 = std::max(h0, h - lastH);
        }
        int w0{0}, lastW{0};
        for (int curW : verticalCuts) {
            w0 = std::max(w0, curW - lastW);
            lastW = curW;
        }
        if (lastW < w) {
            w0 = std::max(w0, w - lastW);
        }
        unsigned long long int ans{static_cast<unsigned long long int>(h0) * w0 % MOD};
        return static_cast<int>(ans);
    }
};