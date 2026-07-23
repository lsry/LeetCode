#include <cmath>
#include <cstdlib>
#include <vector>
using std::vector;

struct UnionFind {
    vector<int> ids, ranks;
    UnionFind(int n): ids(n), ranks(n, 1) {
        for (int i = 0;i < n;++i) {
            ids[i] = i;
        }
    }

    int toFind(int id) {
        while (ids[id] != id) {
            id = ids[id];
        }
        return id;
    }

    void toUnion(int p, int q) {
        int pid = toFind(p);
        int qid = toFind(q);
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
    }

    bool connected(int p, int q) {
        return toFind(p) == toFind(q);
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionFind uf(n);
        for (int i = 0, j = 0;j < n;++j) {
            while (i < j && std::abs(nums[i] - nums[j]) > maxDiff) {
                ++i;
            }
            if (i < j) {
                uf.toUnion(i, j);
            }
        }
        int QN = queries.size();
        vector<bool> ans(QN, false);
        for (int i = 0;i < QN;++i) {
            bool f = uf.connected(queries[i][0], queries[i][1]);
            ans[i] = f;
        }
        return ans;
    }
};
