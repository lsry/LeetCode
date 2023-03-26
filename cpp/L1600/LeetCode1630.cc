#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    /**
     * O(n * nlgn)
     */
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        std::size_t n{l.size()};
        vector<bool> flags(n, false);
        vector<int> tmp;
        for (std::size_t i{0};i < n;++i) {
            int c{r[i] - l[i] + 1};
            if (c < 2) {
                flags[i] = false;
            } else if (c == 2) {
                flags[i] = true;
            } else {
                tmp.clear();
                for (int x{l[i]};x <= r[i];++x) {
                    tmp.push_back(nums[i]);
                }
                std::stable_sort(tmp.begin(), tmp.end());
                flags[i] = true;
                for (int x{2};x < c;++x) {
                    if (tmp[x] - tmp[x - 1] != tmp[1] - tmp[0]) {
                        flags[i] = false;
                        break;
                    }
                }
            }
        }
        return flags;
    }
};