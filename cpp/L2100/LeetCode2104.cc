#include <vector>
using std::vector;

#include <stack>
using std::stack;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        sz = nums.size();
        vector<long long> min = find(nums, true);
        vector<long long> max = find(nums, false);
        long long res{0};
        for (int i = 0;i < sz;++i) {
            res += (max[i] - min[i]) * nums[i];
        }
        return res;
    }

private:
    int sz;
    vector<long long> find(vector<int> &nums, bool min) {
        vector<int> lx(sz), rx(sz);
        stack<int> st;
        for (int i= 0;i < sz;++i) {
            while (!st.empty() && (min ? (nums[st.top()] >= nums[i]) : (nums[st.top()] <= nums[i]))) {
                st.pop();
            }
            lx[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        stack<int> st2;
        for (int i = sz - 1;i >= 0;--i) {
            while (!st2.empty() && (min ? (nums[st2.top()] > nums[i]) :(nums[st2.top()] < nums[i]))) {
                st2.pop();
            }
            rx[i] = st2.empty() ? sz : st2.top();
            st2.push(i);
        }
        vector<long long> res(sz);
        for (int i = 0;i < sz;++i) {
            res[i] = (long long)(i - lx[i]) * (rx[i] - i);
        }
        return res;
    }
};