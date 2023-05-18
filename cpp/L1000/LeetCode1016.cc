#include <string>
using std::string;
#include <unordered_set>

class Solution {
    int countDigit(int n) {
        int ans{0};
        while (n != 0) {
            ++ans;
            n = n >> 1;
        }
        return ans;
    }
public:
    bool queryString(string s, int n) {
        if (n == 1 && s.find("1") != string::npos) {
            return true;
        }
        int k = countDigit(n);
        int m = s.size();
        int la = 1 << (std::max(k - 2, 0));
        if (m < la + k - 1 || m < n - (1 << (k - 1)) + k + 1) {
            return false;
        }
        std::unordered_set<int> st;
        for (int i = 0;i + k - 1 <= m;++i) {
            int num{0};
            for (int j = i;j < i + k - 1;++j) {
                num = num << 1;
                if (s[j] == '1') {
                    num += 1;
                }
            }
            if (num >= la && num <= n) {
                st.emplace(num);
            }
        }
        for (int i = 0;i + k <= m;++i) {
            int num{0};
            for (int j = i;j < i + k;++j) {
                num = num << 1;
                if (s[j] == '1') {
                    num += 1;
                }
            }
            if (num >= la && num <= n) {
                st.emplace(num);
            }
        }
        return st.size() == n - la + 1;
    }
};