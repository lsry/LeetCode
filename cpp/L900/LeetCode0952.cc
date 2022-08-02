#include <vector>
using std::vector;

class UnionFind
{
private:
    vector<int> ids, rank;
public:
    UnionFind(int n) : ids(n), rank(n) {
        for (int i = 0;i < n;++i) {
            rank[i] = 1;
            ids[i] = i;
        }
    };

    int findF(int id) {
        while (id != ids[id]) {
            id = ids[id];
        }
        return id;
    }
    
    void unionF(int p, int q) {
        int pid = findF(p);
        int qid = findF(q);
        if (pid == qid) {
            return;
        }
        if (rank[pid] < rank[qid]) {
            ids[pid] = qid;
        } else if (rank[pid] > rank[qid]) {
            ids[qid] = pid;
        } else {
            ids[pid] = qid;
            rank[qid]++;
        }
    }
};


class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int maxNum = 0;
        for (int num : nums) {
            maxNum = std::max(maxNum, num);
        }
        UnionFind uf(maxNum + 1);
        for (int num : nums) {
            for (int i = 2;i * i <= num;++i) {
                if (num % i == 0) {
                    uf.unionF(num, num / i);
                    uf.unionF(num, i);
                }
            }
        }
        vector<int> count(maxNum + 1);
        int res = 1;
        for (int num : nums) {
            int nid = uf.findF(num);
            count[nid] += 1;
            res = std::max(res, count[nid]);
        }
        return res;
    }
};