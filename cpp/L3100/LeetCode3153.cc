#include <algorithm>
#include <array>
#include <vector>
using std::vector;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        std::array<long long int, 10> bits{{0}};
        long long int ans{0LL};
        long long int mod{1LL};
        int N = nums.size();
        for (int i = 1;i <= 9;++i, mod *= 10) {
            std::fill(bits.begin(), bits.end(), 0);
            for (int num : nums) {
                int c = num / mod % 10;
                bits[c] += 1;
            }
            int count{N};
            for (int j = 0;j < 10;++j) {
                if (bits[j] > 0) {
                    ans += 1LL * bits[j] * (count - bits[j]);
                    count -= bits[j];
                }
            }
        }
        return ans;
    }
};