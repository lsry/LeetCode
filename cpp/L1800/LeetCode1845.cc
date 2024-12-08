#include <queue>
#include <vector>

class SeatManager {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
public:
    SeatManager(int n) {
        for (int i = 1;i <= n;++i) {
            pq.emplace(i);
        }
    }
    
    int reserve() {
        int x = pq.top();
        pq.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        pq.emplace(seatNumber);
    }
};