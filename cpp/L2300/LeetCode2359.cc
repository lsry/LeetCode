#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> disA(edges.size(), std::numeric_limits<int>::max());
        for (int step{0}, node{node1};node != -1;node = edges[node], ++step) {
            if (disA[node] != std::numeric_limits<int>::max()) {
                break;
            }
            disA[node] = step;
        }
        vector<int> disB(edges.size(), std::numeric_limits<int>::max());
        for (int step{0}, node{node2};node != -1;node = edges[node], ++step) {
            if (disB[node] != std::numeric_limits<int>::max()) {
                break;
            }
            disB[node] = step;
        }
        int rn{-1}, rd{std::numeric_limits<int>::max()};
        for (int i = 0;i < edges.size();++i) {
            int minV{std::max(disA[i], disB[i])};
            if (minV < rd) {
                rn = i;
                rd = minV;
            }
        }
        return rn;
    }
};