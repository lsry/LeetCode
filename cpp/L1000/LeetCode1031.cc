#include <vector>
using std::vector;

#include <stack>

class Solution {
    int maxSumArray(vector<int>& nums, int firstLen, int secondLen) {
        int nz = nums.size();
        std::stack<std::pair<int, int>> st;
        int sum{0};
        for (int right = nz - 1, left = nz - 1;left >= 0;--left) {
            sum += nums[left];
            int len = right - left + 1;
            if (len < secondLen) {
                continue;
            }
            if (st.empty() || st.top().second < sum) {
                st.push({left, sum});
            }
            sum -= nums[right];
            --right;
        }
        sum = 0;
        int maxSum{0};
        for (int left = 0, right = 0;right < nz - 1;++right) {
            sum += nums[right];
            int len = right - left + 1;
            if (len < firstLen) {
                continue;
            } 
            while (!st.empty() && st.top().first <= right) {
                st.pop();
            }
            if (st.empty()) {
                break;
            }
            maxSum = std::max(maxSum, sum + st.top().second);
            sum -= nums[left];
            ++left;
        }
        return maxSum;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return std::max(maxSumArray(nums, firstLen, secondLen), maxSumArray(nums, secondLen, firstLen));
    }
};