#include <vector>
using std::vector;

struct Element {
    int left, right, value;

    Element(int left, int right, int value): left(left), right(right), value(value) {}
};
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int N = nums.size();
        vector<Element> stack;
        for (int i = 0;i < N;++i) {
            Element e(i, i, nums[i]);
            while (!stack.empty() && stack.back().value > nums[i]) {
                Element top = stack.back();
                stack.pop_back();
                e.value = std::max(top.value, e.value);
                e.left = top.left;
            }
            stack.push_back(e);
        }
        vector<int> ans(N, 0);
        for (Element e : stack) {
            for (int i = e.left;i <= e.right;++i) {
                ans[i] = e.value;
            }
        }
        return ans;
    }
};
