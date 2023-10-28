#include <cmath>
#include <functional>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        std::priority_queue<int, vector<int>, std::less<int>> pq(gifts.begin(), gifts.end());
        for (int i{0};i < k;++i) {
            int gift = pq.top();
            pq.pop();
            pq.push(static_cast<int>(std::sqrt(gift)));
        }
        long long int ans{0LL};
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};