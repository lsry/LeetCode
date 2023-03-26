#include <vector>
#include <array>

class Solution {
    static std::array<std::array<int, 10>, 10> pres;
public:
    Solution() {
        for (int i = 1;i < 10;++i) {
            for (int j = i;j < 10;++j) {
                int m{1};
                for (int k = i;k <= j;++k) {
                    m *= k;
                }
                pres[i][j] = m;
            }
        } 
    }
    int numDupDigitsAtMostN(int n) {
        return n + 1 - dp(n);
    }

    int dp(int n) {
        if (n <= 10) {
            return n + 1;
        }
        std::vector<int> digits;
        int t{n};
        while (t != 0) {
            digits.push_back(t % 10);
            t /= 10;
        }
        int sz = digits.size(), ans{0};
        for (int i{sz - 1}, p{1}, state{0};i >= 0;--i, ++p) {
            int digit{digits[i]}, cnt{0};
            for (int j{0};j < digit;++j) {
                if (j == 0 && i == sz - 1) {
                    continue;
                }
                if (((1 << j) & state) == 0) {
                    ++cnt;
                }
            }
            int left{10 - p};
            int right{left - (sz - p) + 1};
            ans += (left >= right) ? cnt * pres[right][left] : cnt;
            if ((state & (1 << digit)) != 0) {
                break;
            }
            state |= (1 << digit);
            if (i == 0) {
                ++ans; // add n-self
            }
        }
        ans += 10; // [0-9]
        for (int last{9}, cur{9}, i{2};i < sz;++i, --cur) {
            last *= cur;
            ans += last;
        }
        return ans;
    }
};

std::array<std::array<int, 10>, 10> Solution::pres{};