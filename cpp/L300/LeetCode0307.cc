#include <vector>
using std::vector;

class NumArray {
private:
    const int sz;
    vector<int> tree;
    vector<int> &original;

    int lowbit(int x) {
        return x & (-x);
    }
public:
    NumArray(vector<int>& nums) : sz(nums.size()), original(nums) {
        tree.resize(sz + 1, 0);
        for (int i = 0;i < sz;++i) {
            tree[i + 1] = nums[i];
        }
        for (int i = 1;i <= sz;++i) {
            int j = i + lowbit(i);
            if (j <= sz) {
                tree[j] = tree[j] + tree[i];
            }
        }
    }
    
    void update(int index, int val) {
        int delta = val - original[index];
        original[index] = val;
        int nx = index + 1;
        while (nx <= sz) {
            tree[nx] += delta;
            nx += lowbit(nx);
        }
    }

    int preSum(int index) {
        int sum = 0;
        for (int idx = index + 1;idx > 0;idx = idx - lowbit(idx)) {
            sum += tree[idx];
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        return preSum(right) - preSum(left - 1);
    }
};