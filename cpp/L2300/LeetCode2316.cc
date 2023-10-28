#include <numeric>
#include <vector>
using std::vector;

struct UnionFind {
    int n;
    vector<int> ids, ranks;

    UnionFind(int n): n(n), ids(n), ranks(n, 1) {
        std::iota(ids.begin(), ids.end(), 0);
    }

    int find(int id) {
        while (ids[id] != id) {
            id = ids[id];
        }
        return id;
    }

    long long to_union(int p, int q) {
        int pid = find(p);
        int qid = find(q);
        if (pid == qid) {
            return 0;
        }
        long long ans = 1LL * ranks[pid] * ranks[qid];
        if (ranks[pid] >= ranks[qid]) {
            ids[qid] = pid;
            ranks[pid] += ranks[qid];
        } else {
            ids[pid] = qid;
            ranks[qid] += ranks[pid];
        }
        return ans;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }
};

class Solution {
    
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        long long ans{1LL * (n - 1) * n / 2LL};
        for (vector<int> const &edge : edges) {
            if (uf.connected(edge[0], edge[1])) {
                continue;
            }
            long long cur = uf.to_union(edge[0], edge[1]);
            ans -= cur;
        }
        return ans;
    }
};