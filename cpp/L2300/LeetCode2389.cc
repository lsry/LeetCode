#include <vector>
using std::vector;
#include <queue>
#include <algorithm>

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        std::size_t M{queries.size()};
        vector<int> indics(M, 0), res(M, 0);
        for (int i = 0;i < M;++i) {
            indics[i] = i;
        }
        std::sort(indics.begin(), indics.end(), [&](int a, int b) {
            return queries[a] >= queries[b];
        });
        std::priority_queue<int, vector<int>, std::less<int>> pq;
        int sum{0};
        for (int num : nums) {
            sum += num;
            pq.push(num);
        }
        for (int id : indics) {
            while (!pq.empty() && sum > queries[id]) {
                int t = pq.top();
                pq.pop();
                sum -= t;
            }
            res[id] = pq.size();
        }
        return res;
    }
};