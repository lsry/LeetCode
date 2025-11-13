#include <functional>
#include <queue>
#include <vector>
using std::vector;

class UnionFind {
    vector<int> ids, ranks;
    vector<std::priority_queue<int, vector<int>, std::greater<int>>> idPq;
    vector<bool> offines;

    void mergePq(std::priority_queue<int, vector<int>, std::greater<int>> &enter,
                 std::priority_queue<int, vector<int>, std::greater<int>> &outer) {
        while (!outer.empty()) {
            int i = outer.top();
            outer.pop();
            if (!offines[i]) {
                enter.push(i);
            }
        }
    }
public:
    UnionFind(int c): ids(c, 0), ranks(c, 1), idPq(c, std::priority_queue<int, vector<int>, std::greater<int>>()), offines(c, false) {
        for (int i = 0;i < c;++i) {
            ids[i] = i;
            idPq[i].push(i);
        }
    }

    int findId(int id) {
        while (ids[id] != id) {
            id = ids[id];
        }
        return id;
    }

    void toUnion(int p, int q) {
        int pid = findId(p);
        int qid = findId(q);
        if (pid == qid) {
            return;
        }
        if (ranks[pid] >= ranks[qid]) {
            ids[qid] = pid;
            ranks[pid] += ranks[qid];
            mergePq(idPq[pid], idPq[qid]);
        } else {
            ids[pid] = qid;
            ranks[qid] += ranks[pid];
            mergePq(idPq[qid], idPq[pid]);
        }
    }

    int getMaintainId(int id) {
        if (!offines[id]) {
            return id;
        }
        id = findId(id);
        while (!idPq[id].empty() && offines[idPq[id].top()]) {
            idPq[id].pop();
        }
        return idPq[id].empty() ? -1 : idPq[id].top();
    }

    void toOffline(int p) {
        offines[p] = true;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind uf(c);
        for (vector<int> const &conn : connections) {
            uf.toUnion(conn[0] - 1, conn[1] - 1);
        }
        vector<int> ans;
        for (vector<int> const &query : queries) {
            if (query[0] == 2) {
                uf.toOffline(query[1] - 1);
            } else if (query[0] == 1) {
                int id = uf.getMaintainId(query[1] - 1);
                ans.push_back(id == -1 ? -1 : id + 1);
            }
        }
        return ans;
    }
};
