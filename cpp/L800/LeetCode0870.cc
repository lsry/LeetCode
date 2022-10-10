#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        std::stable_sort(nums1.begin(), nums1.end());
        std::size_t nz{nums1.size()};
        std::vector<std::size_t> n2i;
        for (std::size_t i{0};i < nz;++i) {
            n2i.push_back(i);
        }
        std::stable_sort(n2i.begin(), n2i.end(), [&](std::size_t const &a, std::size_t const & b) -> bool {
            return nums2[a] <= nums2[b];
        });
        std::vector<int> res(nz, 0);
        std::vector<int> pool;
        for (std::size_t i{0}, j{0}, k{0};j < nz;++j) {
            while (i < nz && nums1[i] <= nums2[n2i[j]]) {
                pool.push_back(nums1[i]);
                ++i;
            }
            if (i < nz) {
                res[n2i[j]] = nums1[i];
                ++i;
            } else {
                res[n2i[j]] = pool[k];
                ++k;
            }
        }
        return res;
    }
};