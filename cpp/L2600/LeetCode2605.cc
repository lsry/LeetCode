#include <algorithm>
#include <array>
#include <vector>
using std::vector;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        std::array<bool, 10> flags;
        std::fill(flags.begin(), flags.end(), false);
        int n1{nums1[0]}, n2{nums2[0]};
        for (int n : nums1) {
            flags[n] = true;
            n1 = std::min(n1, n);
        }
        int a{10};
        for (int n : nums2) {
            if (flags[n]) {
                a = std::min(a, n);
            }
            n2 = std::min(n2, n);
        }
        if (a != 10) {
            return a;
        }
        return n1 < n2 ? n1 * 10 + n2 : n2 * 10 + n1;
    }
};