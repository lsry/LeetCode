#include <algorithm>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        auto f{[&](int x, int y) {
            return nums[x] > nums[y];
        }};
        std::priority_queue<int, vector<int>, decltype(f)> pq(f);
        for (int i = 0;i < nums.size();++i) {
            if (pq.size() == k && nums[pq.top()] < nums[i]) {
                pq.pop();
                pq.push(i);
            } else if (pq.size() < k) {
                pq.push(i);
            }
        }
        vector<int> r;
        r.reserve(k);
        while (!pq.empty()) {
            r.push_back(pq.top());
            pq.pop();
        }
        std::sort(r.begin(), r.end());
        for (int i = 0;i < k;++i) {
            r[i] = nums[r[i]];
        }
        return r;
    }
};