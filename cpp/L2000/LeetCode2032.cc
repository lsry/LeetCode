#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<vector<bool>> arrs(3, vector<bool>(101));
        for (int num : nums1) {
            arrs[0][num] = true;
        }
        for (int num : nums2) {
            arrs[1][num] = true;
        }
        for (int num : nums3) {
            arrs[2][num] = true;
        }
        vector<int> res;
        for (int i = 1;i < 101;++i) {
            int a = arrs[0][i] ? 1 : 0;
            a += arrs[1][i] ? 1 : 0;
            a += arrs[2][i] ? 1 : 0;
            if (a > 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};