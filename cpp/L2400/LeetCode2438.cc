#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pows;
        for (int i = 0;i < 31;++i) {
            if (((n >> i) & 1) == 1) {
                pows.emplace_back(1 << i);
            }
        }    
        vector<int> ans;
        ans.reserve(queries.size());  
        for (vector<int> const &q : queries) {
            unsigned long long int cur{1ULL};
            for (int i = q[0];i <= q[1];++i) {
                cur = (cur * pows[i]) % MOD;
            }
            ans.emplace_back(static_cast<int>(cur));
        }
        return ans;
    }
};