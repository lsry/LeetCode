#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        auto f{[](std::pair<int, int> const &p1, std::pair<int, int> const &p2) {
            return p1.second > p2.second;
        }};
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(f)> pq;
        int curDay{0};
        int appleCount{0};
        for (int i = 0;i < apples.size();++i) {
            if (apples[i] > 0) {
                pq.push(std::pair<int, int>(apples[i], i + days[i]));
            }
            while (!pq.empty() && pq.top().second <= curDay) {
                pq.pop();
            }
            if (!pq.empty()) {
                auto const [apple, limitDay] = pq.top();
                pq.pop();
                appleCount += 1;
                if (apple - 1 > 0) {
                    pq.push(std::pair<int, int>(apple - 1, limitDay));
                }
            }
            curDay += 1;
        }     
        while (!pq.empty()) {
            auto const [apple, limitDay] = pq.top();
            pq.pop();
            if (limitDay <= curDay) {
                continue;
            }
            int eatenApples = std::min(apple, limitDay - curDay);
            appleCount += eatenApples;
            curDay += eatenApples;
        }
        return appleCount;
    }
};