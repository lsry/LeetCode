#include <vector>
using std::vector;

struct UnionFind {
    vector<int> ids, ranks;
    int count;

    UnionFind(int n):ids(n), ranks(n), count(n) {
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

    void to_union(int p, int q) {
        int pid{to_find(p)}, qid{to_find(q)};
        if (pid == qid) {
            return;
        }
        if (ranks[pid] >= ranks[qid]) {
            ids[qid] = pid;
            ranks[pid] += ranks[qid];
        } else {
            ids[pid] = qid;
            ranks[qid] += ranks[pid];
        }
        count--;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int N = row.size();
        UnionFind uf(N / 2);
        for (int i = 0;i < N;i += 2) {
            uf.to_union(row[i] / 2, row[i + 1] / 2);
        }
        return N / 2 - uf.count;
    }
};