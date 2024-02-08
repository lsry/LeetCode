#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        auto f{[](std::pair<int, int> const &p1, std::pair<int, int> const &p2) {
            return p1.first < p2.first;
        }};
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(f)> pq(f);
        int N = nums.size();
        for (int i = 0;i < N;++i) {
            while (!pq.empty() && pq.top().second < i - k) {
                pq.pop();
            }
            if (pq.empty()) {
                pq.push(std::pair<int, int>(nums[i], i));
            } else {
                int x = pq.top().first + nums[i];
                pq.push(std::pair<int, int>(x, i));
            }
        }
        while (!pq.empty() && pq.top().second != N - 1) {
            pq.pop();
        }
        return pq.top().first;
    }
};