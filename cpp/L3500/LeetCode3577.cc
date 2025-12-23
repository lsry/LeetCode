#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    int countPermutations(vector<int>& complexity) {
        int N = complexity.size();
        unsigned long long int ans{1ULL};
        for (int i = 1;i < N;++i) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
            ans = (ans * i) % MOD;
        }
        return ans;
    }
};
