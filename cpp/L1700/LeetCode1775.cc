#include <vector>
using std::vector;

#include <numeric>
#include <algorithm>

class Solution {
    int step(vector<int>& nums1, int sum1, vector<int>& nums2, int sum2) {
        int diff = sum1 - sum2;
        int step = 0;
        if (diff == 0) {
            return step;
        }
        auto it1 = nums1.rbegin();
        auto it2 = nums2.begin();
        while (diff > 0 && (it1 != nums1.rend() || it2 != nums2.end())) {
            if (it1 == nums1.rend()) {
                if (6 - *it2 >= diff) {
                    diff = 0;
                } else {
                    diff -= (6 - *it2);
                }
                ++it2;
            } else if (it2 == nums2.end()) {
                if (*it1 - 1 >= diff) {
                    diff = 0;
                } else {
                    diff -= (*it1 - 1);
                }
                ++it1;
            } else if ((*it1 - 1) >= (6 - *it2)) {
                if (*it1 - 1 >= diff) {
                    diff = 0;
                } else {
                    diff -= (*it1 - 1);
                }
                ++it1;
            } else {
                if (6 - *it2 >= diff) {
                    diff = 0;
                } else {
                    diff -= (6 - *it2);
                }
                ++it2;
            }
            ++step;
        }
        return diff == 0 ? step : -1;
    }
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int sum1 = std::accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = std::accumulate(nums2.begin(), nums2.end(), 0);
        return sum1 > sum2 ? step(nums1, sum1, nums2, sum2) : step(nums2, sum2, nums1, sum1);
    }
};