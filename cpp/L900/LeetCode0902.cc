#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cmath>

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int dz = digits.size();
        vector<int> nums;
        for (string const &digit : digits) {
            nums.push_back(digit[0] - '0');
        }
        vector<int> nits;
        while (n != 0) {
            nits.push_back(n % 10);
            n /= 10;
        }
        int nz = nits.size();
        int ans = 0;
        // 當數位相同時
        for (int i = nz - 1, p = 1;i >= 0;--i, ++p) {
            int r = 0;
            while (r < dz && nums[r] < nits[i]) {
                ++r;
            }
            if (r >= dz) {
                ans += r * (int)std::pow(dz, nz - p);
                break;
            } else if (nums[r] == nits[i]) {
                ans += r * (int)std::pow(dz, nz - p);
                if (i == 0) {
                    ans += 1;
                }
            } else {
                if (r > 0) {  // ["3", "5"] 4
                    ans += r * (int)std::pow(dz, nz - p);
                }
                break;
            }
        }
        // 當數位小於給定數字時
        for (int i = 1, last = 1;i < nz;++i) {
            last *= dz;
            ans += last;
        }
        return ans;
    }
};