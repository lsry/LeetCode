class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int concatenatedBinary(int n) {
        unsigned long long int ans{0ULL};
        for (int i = 1;i <= n;++i) {
            int cnt{0};
            for (int num = i;num > 0;num = num >> 1) {
                ++cnt;
            }
            ans = ((ans << cnt) + i) % MOD;
        }
        return ans;
    }
};
