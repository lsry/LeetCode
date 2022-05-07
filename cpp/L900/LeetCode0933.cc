#include <queue>
using std::priority_queue;

#include <vector>
using std::vector;

class RecentCounter {
private:
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        pq.push(t);
        while (!pq.empty() && t - pq.top() > 3000) {
            pq.pop();
        }
        return pq.size();
    }
};