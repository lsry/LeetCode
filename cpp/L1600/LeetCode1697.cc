#include <vector>
using std::vector;
#include <algorithm>

class Solution {
    struct UnionFind {
        std::vector<int> ids, ranks;

        UnionFind(int n): ids(n), ranks(n) {
            for (int i = 0;i < n;++i) {
                ids[i] = i;
                ranks[i] = 1;
            }
        }

        int tofind(int id) {
            while (ids[id] != id) {
                id = ids[id];
            }
            return id;
        }

        void toUnion(int pid, int qid) {
            pid = tofind(pid);
            qid = tofind(qid);
            if (ranks[pid] >= ranks[qid]) {
                ids[qid] = pid;
            } else {
                ids[pid] = qid;
            }
            if (pid != qid && ranks[qid] == ranks[pid]) {
                ranks[pid] += ranks[qid];
            }
        }

        bool connected(int pid, int qid) {
            return tofind(pid) == tofind(qid);
        }
    };
    
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        std::sort(edgeList.begin(), edgeList.end(), [](auto const &e1, auto const &e2) -> bool {
            return e1[2] < e2[2];
        });
        std::size_t qz{queries.size()};
        for (int i{0};i < qz;++i) {
            queries[i].push_back(i);
        }
        std::sort(queries.begin(), queries.end(), [](auto const &e1, auto const &e2) -> bool {
            return e1[2] < e2[2];
        });

        UnionFind uf(n);
        std::size_t ez(edgeList.size()), ei{0};
        vector<bool> res(qz, false);
        for (vector<int> const &query : queries) {
            while (ei < ez && edgeList[ei][2] < query[2]) {
                uf.toUnion(edgeList[ei][0], edgeList[ei][1]);
                ++ei;
            }
            res[query[3]] = uf.connected(query[0], query[1]);
        }
        return res;
    }
};