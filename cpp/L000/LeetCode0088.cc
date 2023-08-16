#include <vector>
using std::vector;

class Solution {
public:
    void mergePositive(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i{0}, j{0};i < m || j < n;) {
            if (j >= n) {
                break;
            }
            if (i >= m) {
                nums1[i] = nums2[j];
                ++j;
                ++i;
            } else if (nums1[i] <= nums2[j]) {
                ++i;
            } else {
                std::swap(nums1[i], nums2[j]);
                for (int k{j + 1};k < n && nums2[k] < nums2[k - 1];++k) {
                    std::swap(nums2[k], nums2[k - 1]);
                }
                ++i;
            }
        }
    }
    
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        for (int i{m - 1}, j{n - 1}, k{m + n - 1};i >= 0 || j >= 0;--k) {
            if (j < 0) {
                break;
            }
            if (i < 0) {
                nums1[k] = nums2[j];
                --j;
            } else if (nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                --i;
            } else {
                nums1[k] = nums2[j];
                --j;
            }
        }
    }
};