#include <vector>
using std::vector;

class UnionFind
{
private:
    vector<int> ids, rank;
    int n_;
public:
    UnionFind(int n): ids(n), n_(n), rank(n) {
        for (int i = 0;i < n;++i) {
            ids[i] = i;
            rank[i] = 1;
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
        if (rank[pid] <= rank[qid]) {
            ids[pid] = qid;
        } else {
            ids[qid] = pid;
        }
        if (pid != qid && rank[pid] == rank[qid]) {
            rank[qid] += 1;
        }
    }
    bool connected(int p, int q) {
        return toFind(p) == toFind(q);
    }
};


class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> nexts(n + 1, vector<int>());
        for (vector<int> dislike : dislikes) {
            nexts[dislike[0]].push_back(dislike[1]);
            nexts[dislike[1]].push_back(dislike[0]);
        }
        UnionFind uf(n + 1);
        for (int i = 1;i <= n;++i) {
            int nz = nexts[i].size();
            for (int j = 0;j < nz;++j) {
                // 將所有不喜歡的人放到一起
                uf.toUnion(nexts[i][0], nexts[i][j]);
                if (uf.connected(i, nexts[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }
};