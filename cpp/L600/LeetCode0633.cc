#include <cmath>
#include <unordered_set>
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int NUM_LIMIT = 46340LL;
        std::unordered_set<long long int> st;
        for (long long int i = 0LL;i <= NUM_LIMIT;++i) {
            if (2 * i * i == c || st.contains(c - i * i)) {
                return true;
            }
            st.emplace(i * i);
        }
        return false;
    }
};