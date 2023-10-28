#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, std::less<int>> pq(nums.begin(), nums.end());
        long long ans{0LL};
        for (int i = 0;i < k && !pq.empty() && pq.top() > 0;++i) {
            int top{pq.top()};
            pq.pop();
            ans = ans + top;
            pq.push(top %  3 == 0 ? top / 3 : top /  3 + 1);
        }
        return ans;
    }
};