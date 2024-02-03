#include <vector>
using std::vector;
#include <array>

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int nz = nums.size();
        std::array<int, 51> counts{0};
        vector<int> suffix(nz, 0);
        int count{0};
        for (int i = nz - 1;i >= 0;--i) {
            counts[nums[i]] += 1;
            if (counts[nums[i]] == 1) {
                count += 1;
            }
            suffix[i] = count;
        }
        std::fill(counts.begin(), counts.end(), 0);
        count = 0;
        for (int i = 0;i < nz;++i) {
            int suffixCount = i + 1 >= nz ? 0 : suffix[i + 1];
            counts[nums[i]] += 1;
            if (counts[nums[i]] == 1) {
                count += 1;
            }
            suffix[i] = count - suffixCount;
        }
        return suffix;
    }
};