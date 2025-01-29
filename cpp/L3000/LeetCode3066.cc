#include <functional>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::priority_queue<long long int, vector<long long int>, std::greater<long long int>> pq;
        for (int num : nums) {
            pq.push(num);
        }
        int ans{0};
        while (pq.size() > 1 && pq.top() < k) {
            long long int x = pq.top();
            pq.pop();
            long long int y = pq.top();
            pq.pop();
            long long int z = std::min(x, y) * 2 + std::max(x, y);
            pq.push(z);
            ++ans;
        }
        return ans;
    }
};