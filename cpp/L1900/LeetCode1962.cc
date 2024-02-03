#include <functional>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        std::priority_queue<int, vector<int>, std::less<int>> pq;
        int total{0};
        for (int pile : piles) {
            if (pile == 0) {
                continue;
            }
            pq.push(pile);
            total += pile;
        }
        for (int i = 0;i < k && !pq.empty();++i) {
            int top = pq.top();
            pq.pop();
            int minus = top / 2;
            top -= minus;
            total -= minus;
            if (top > 0) {
                pq.push(top);
            }
        }
        return total;
    }
};