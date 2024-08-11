#include <map>
#include <vector>
using std::vector;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, vector<int>> mp;
        int N2 = nums2.size();
        for (int i = N2 - 1;i >= 0;--i) {
            mp[nums2[i]].push_back(i);
        }
        vector<int> counts(N2, 0);
        int ans{0};
        for (int num : nums1) {
            for (int ix : mp[num]) {
                counts[ix] = 1;
                for (int iy = ix - 1;iy >= 0;--iy) {
                    counts[ix] = std::max(counts[ix], counts[iy] + 1);
                }
                ans = std::max(ans, counts[ix]);
            }
        }
        return ans;
    }
};