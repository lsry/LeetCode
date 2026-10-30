#include <algorithm>
#include <functional>
#include <vector>
using std::vector;

class Solution {
    bool check(vector<long long int> const &diff, long long int h, long long int k) {
        long long int ans{0LL};
        for (long long int num : diff) {
            if (num > h) {
                ans += num - h;
            }
        }
        return ans <= k;
    }
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int N = nums1.size();
        vector<long long> diff(N, 0LL);
        long long int left{0}, right{0}, k{k1 + k2};
        for (int i = 0;i < N;++i) {
            diff[i] = std::abs(nums1[i] - nums2[i]);
            right = std::max(diff[i], right);
        }
        long long int res{right};
        while (left <= right) {
            long long int mid{(left + right) / 2};
            if (check(diff, mid, k)) {
                right = mid - 1;
                res = mid;
            } else {
                left = mid + 1;
            }
        }
        long long int ans{0LL};
        for (long long int num : diff) {
            if (num > res) {
                k -= (num - res);
            }
        }
        std::sort(diff.begin(),diff.end(), std::greater<long long int>());
        for (long long int num : diff) {
            long long int d = num > res ? res : num;
            if ((k && d) > 0) {
                --k;
                --d;
            }
            ans += d * d;
        }
        return ans;
    }
};
