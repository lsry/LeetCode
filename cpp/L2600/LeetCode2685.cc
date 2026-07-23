#include <vector>
using std::vector;

class Solution {
    int findId(int id, vector<int> const &ids) {
        while (ids[id] != id) {
            id = ids[id];
        }
        return id;
    }

    void toUnion(int p, int q, vector<vector<int>> &arrays) {
        int pid = findId(p, arrays[0]);
        int qid = findId(q, arrays[0]);
        if (pid == qid && p != q) {
            arrays[2][pid] += 1;
        } else if (pid != qid) {
            if (arrays[1][pid] > arrays[1][qid]) {
                arrays[0][qid] = pid;
                arrays[1][pid] += arrays[1][qid];
                arrays[2][pid] += arrays[2][qid];
                arrays[2][pid] += 1;
            } else {
                arrays[0][pid] = qid;
                arrays[1][qid] += arrays[1][pid];
                arrays[2][qid] += arrays[2][pid];
                arrays[2][qid] += 1;
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        std::vector<vector<int>> arrays(3, vector<int>(n, 0));
        for (int i = 0;i < n;++i) {
            arrays[0][i] = i;
            arrays[1][i] = 1;
            arrays[2][i] = 0;
        }
        for (vector<int> const &edge : edges) {
            toUnion(edge[0], edge[1], arrays);
        }
        int ans{0};
        for (int i = 0;i < n;++i) {
            if (arrays[0][i] == i && arrays[2][i] == arrays[1][i] * (arrays[1][i] - 1) / 2) {
                ++ans;
            }
        }
        return ans;
    }
};
