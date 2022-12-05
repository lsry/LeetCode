#include <vector>
using std::vector;

#include <deque>

/**
 * 单调递减队列
 * front：队头，代表最大值索引，如果超出窗口则出队
 * back：队尾，保证待添加元素小于队中每个元素
 * 解析：假设 i, j, k 处于同一窗口，i < j 时，A[i] < A[j], 则 A[i] 无法作为窗口中最大值
 *      但是 当 j < k 时，A[j] > A[k], 当 j 在窗口外出队，A[j] 却有可能作为最大值被选择
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> q;
        int nz{static_cast<int>(nums.size())};
        for (int i = 0;i < k - 1;++i) {
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        std::vector<int> res;
        for (int i = k - 1;i < nz;++i) {
            while (!q.empty() && q.front() < i - k + 1) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};