#include <vector>
using std::vector;
#include <algorithm>

class Node
{  
public:
    vector<int> interval;
    int id;
    Node(vector<int> &interval, int id) : interval(interval), id(id) {}
    ~Node() {}
};


class Solution {
private:
    int nz;
    int binSearch(vector<Node> const &nodes, int end) {
        int left = 0, right = nz - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nodes[mid].interval[0] < end) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left >= nz ? -1 : nodes[left].id;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        nz = intervals.size();
        vector<Node> nodes;
        for (int i = 0;i < nz;++i) {
            nodes.push_back(Node(intervals[i], i));
        }
        std::stable_sort(nodes.begin(), nodes.end(), [](Node const &a, Node const &b) -> bool {
            return a.interval[0] < b.interval[0];
        });
        vector<int> res;
        for (vector<int> &interval : intervals) {
            res.push_back(binSearch(nodes, interval[1]));
        }
        return res;
    }
};