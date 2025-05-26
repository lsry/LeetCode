#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size(), Q = queries.size();
        std::sort(queries.begin(), queries.end(), [](vector<int> const &q1, vector<int> const &q2) {
            return q1[0] < q2[0];
        });
        vector<int> diff(N + 1, 0);

        std::priority_queue<int, vector<int>, std::less<int>> pq;
        for (int sum{0}, i{0}, index{0};i < N;++i) {
            sum += diff[i];
            while (index < Q && queries[index][0] == i) {
                pq.push(queries[index][1]);
                ++index;
            }
            while (sum < nums[i] && !pq.empty() && pq.top() >= i) {
                sum += 1;
                diff[pq.top() + 1] -= 1;
                pq.pop();
            }
            if (sum < nums[i]) {
                return -1;
            }
        }
        return pq.size();
    }
};