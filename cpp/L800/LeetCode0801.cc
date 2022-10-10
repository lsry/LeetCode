#include <vector>
using std::vector;

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        std::size_t nz{nums1.size()};
        int a{0}, b{1};  // a: not change, b: change
        for (std::size_t i{1};i < nz;++i) {
            int at{a}, bt{b};
            a = nz, b = nz;
            if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) {
                a = std::min(a, at);
                b = std::min(b, bt + 1);
            }
            if (nums2[i - 1] < nums1[i] && nums1[i - 1] < nums2[i]) {
                a = std::min(a, bt);
                b = std::min(b, at + 1);
            }
        }
        return std::min(a, b);
    }
};
