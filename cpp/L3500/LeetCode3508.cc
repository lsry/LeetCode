#include <algorithm>
#include <deque>
#include <iterator>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>
using std::vector;

class Router {
    int memoryLimit;
    std::set<std::tuple<int, int, int>> addPackets;
    std::queue<std::tuple<int, int, int>> enQueue;
    std::unordered_map<int, std::deque<int>> destinationMap;

public:
    Router(int memoryLimit): memoryLimit(memoryLimit) {}
    
    bool addPacket(int source, int destination, int timestamp) {
        std::tuple<int, int, int> t(source, destination, timestamp);
        if (addPackets.contains(t)) {
            return false;
        }
        if (enQueue.size() >= memoryLimit) {
            forwardPacket();
        }
        enQueue.push(t);
        addPackets.insert(t);
        destinationMap[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (enQueue.empty()) {
            return {};
        }
        std::tuple<int, int, int> t = enQueue.front();
        enQueue.pop();
        addPackets.erase(t);
        destinationMap[std::get<1>(t)].pop_front();
        return vector<int>{std::get<0>(t), std::get<1>(t), std::get<2>(t)};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!destinationMap.contains(destination)) {
            return 0;
        }
        std::deque<int> &packets{destinationMap[destination]};
        auto sit{std::lower_bound(packets.begin(), packets.end(), startTime)};
        auto eit{std::lower_bound(packets.begin(), packets.end(), endTime + 1)};
        return std::distance(sit, eit);
    }
};