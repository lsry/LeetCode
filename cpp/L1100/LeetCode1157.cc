#include <vector>
using std::vector;

#include <algorithm>
#include <unordered_map>

struct DataNode
{
    int value, count;
    DataNode(): value(0), count(0) {}

    DataNode& operator+=(DataNode const &that) {
        if (count == 0) {
            value = that.value;
            count = that.count;
        } else if (value == that.value) {
            count += that.count;
        } else if (count > that.count) {
            count -= that.count;
        } else {
            count = that.count - count;
            value = that.value;
        }
        return *this;
    }
};


class MajorityChecker {
    vector<int> const &arr;
    std::unordered_map<int, vector<int>> poses;
    vector<DataNode> trees;
    int an;

    void build_tree(int id, int low, int high) {
        if (low > high) {
            return;
        } else if (low == high) {
            trees[id].value = arr[low];
            trees[id].count = 1;
        } else {
            int mid = (low + high) / 2;
            build_tree(id * 2 + 1, low, mid);
            build_tree(id * 2 + 2, mid + 1, high);
            trees[id] += trees[id * 2 + 1];
            trees[id] += trees[id * 2 + 2];
        }
    }

    void tree_query(int id, int low, int high, int qlow, int qhigh, DataNode &node) {
        if (low > qhigh || high < qlow || low > high) {
            return;
        }
        if (low >= qlow && high <= qhigh) {
            node += trees[id];
            return;
        }
        int mid = (low + high) / 2;
        tree_query(id * 2 + 1, low, mid, qlow, qhigh, node);
        tree_query(id * 2 + 2, mid + 1, high, qlow, qhigh, node);
    }
public:
    MajorityChecker(vector<int>& arr): arr(arr) {
        an = arr.size();
        for (int i = 0;i < an;++i) {
            poses[arr[i]].push_back(i);
        }
        trees.resize(an * 4);
        build_tree(0, 0, an - 1);
    }
    
    int query(int left, int right, int threshold) {
        DataNode node;
        tree_query(0, 0, an - 1, left, right, node);
        if (node.count == 0) {
            return -1;
        }
        vector<int> &nv{poses[node.value]};
        auto f{std::lower_bound(nv.begin(), nv.end(), left)};
        auto e{std::upper_bound(nv.begin(), nv.end(), right)};
        int d = std::distance(f, e);
        return d >= threshold ? node.value : -1;
    }
};