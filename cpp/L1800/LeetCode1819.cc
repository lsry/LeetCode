#include <numeric>
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxNum{*std::max_element(nums.begin(), nums.end())};
        vector<bool> flags(maxNum + 1, false);
        for (int num : nums) {
            flags[num] = true;
        }
        int ans{0};
        for (int i = 1;i <= maxNum;++i) {
            int gcd = 0;
            for (int j = i;j <= maxNum;j += i) {
                if (flags[j]) {
                    if (gcd == 0) {
                        gcd = j;
                    } else {
                        gcd = std::gcd(gcd, j);
                    }
                    if (gcd == i) {
                        ++ans;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};