#include <array>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        std::array<int, 1001> n1{0}, n2{0};
        for (int n : nums1) {
            n1[n] += 1;
        }
        for (int n : nums2) {
            n2[n] += 1;
        }
        for (int i = 0;i <= 1000;++i) {
            int x = std::min(n1[i], n2[i]);
            if (x > 0) {
                for (int j = 0;j < x;++j) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};