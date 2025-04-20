#include <algorithm>
#include <vector>
using std::vector;

class Solution {
    int binarySearchLeast(vector<int> const &nums, int li, int ri, int value) {
        while (li < ri) {
            int mi = (li + ri) / 2;
            if (nums[mi] < value) {
                li = mi + 1;
            } else {
                ri = mi;
            }
        }
        return li;
    }

    int binarySearchMost(vector<int> const &nums, int li, int ri, int value) {
        while (li < ri) {
            int mi = (li + ri) / 2;
            if (nums[mi] > value) {
                ri = mi;
            } else {
                li = mi + 1;
            }
        }
        return li - 1;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int N = nums.size();
        std::sort(nums.begin(), nums.end());
        long long int ans{0LL};
        for (int i = 1;i < N;++i) {
            int leftValue = lower - nums[i];
            int li = binarySearchLeast(nums, 0, i, leftValue);
            int rightValue = upper - nums[i];
            int ri = binarySearchMost(nums, 0, i, rightValue);
            if (li >= i || ri < 0) {
                continue;
            }
            ans += ri - li + 1;
        }      
        return ans;
    }
};