#include <vector>
using std::vector;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans{0LL};
        for (auto ib{nums.begin()}, ie{nums.end() - 1};ib <= ie;--ie, ++ib) {
            if (ib == ie) {
                ans += *ib;
            } else {
                long long first{*ib};
                int x = *ie;
                while (x != 0) {
                    first *= 10LL;
                    x /= 10;
                }
                first += *ie;
                ans += first;
            }
        }
        return ans;
    }
};