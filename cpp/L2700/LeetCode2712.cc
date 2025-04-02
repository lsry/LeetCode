#include <limits>
#include <string>
#include <vector>
using std::string;

class Solution {
public:
    long long minimumCost(string s) {
        int N = s.size();
        std::vector<long long> prefix(N, 0LL);
        for (int i = 1;i < N;++i) {
            if (s[i] == s[i - 1]) {
                prefix[i] = prefix[i - 1];
            } else {
                prefix[i] = i + prefix[i - 1];
            }
        }        
        long long ans{std::numeric_limits<long long int>::max()};
        long long int suffix{0LL};
        for (int i = N - 1;i >= 0;--i) {
            if (i < N - 1) {
                suffix = s[i] == s[i + 1] ? suffix : suffix + N - i - 1;
            }
            ans = std::min(ans, prefix[i] + suffix);
        }
        return ans;
    }
};