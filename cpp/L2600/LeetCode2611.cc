#include <vector>
using std::vector;
#include <numeric>
#include <queue>

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        std::priority_queue<int, vector<int>, std::greater<int>> pq;
        int s2{std::accumulate(reward2.begin(), reward2.end(), 0)};
        int N = reward1.size();
        int ans{0};
        for (int i = 0;i < N;++i) {
            ans += reward1[i] - reward2[i];
            pq.push(reward1[i] - reward2[i]);
            if (pq.size() > k) {
                ans -= pq.top();
                pq.pop();
            }
        }
        return ans + s2;
    }
};