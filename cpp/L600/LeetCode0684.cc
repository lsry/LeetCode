#include <vector>
using std::vector;

struct UnionFind {
    int n;
    vector<int> ids, ranks;

    UnionFind(int n): n(n), ids(n), ranks(n) {
        for (int i = 0;i < n;++i) {
            ids[i] = i;
            ranks[i] = 1;
        }
    }

    int to_find(int id) {
        while (ids[id] != id) {
            id = ids[id];
        }
        return id;
    }

    bool to_union(int p, int q) {
        int pid = to_find(p);
        int qid = to_find(q);
        if (pid == qid) {
            return false;
        }
        if (ranks[pid] >= ranks[qid]) {
            ids[qid] = pid;
            ranks[pid] += ranks[qid];
        } else {
            ids[pid] = qid;
            ranks[qid] += ranks[pid];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());
        for (vector<int> const &edge : edges) {
            bool f = uf.to_union(edge[0] - 1, edge[1] - 1);
            if (!f) {
                return edge;
            }
        }
        return {};
    }
};