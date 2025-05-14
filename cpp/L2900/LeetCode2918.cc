#include <vector>
using std::vector;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long int sumA{0LL}, zeroA{0LL};
        long long int sumB{0LL}, zeroB{0LL};
        for (int num : nums1) {
            sumA += num;
            if (num == 0) {
                ++zeroA;
            }
        }
        for (int num : nums2) {
            sumB += num;
            if (num == 0) {
                ++zeroB;
            }
        }
        if ((zeroA == 0 && sumA < sumB + zeroB) || (sumA + zeroA > sumB && zeroB == 0)) {
            return -1;
        }
        return std::max(sumA + zeroA, sumB + zeroB);
    }
};