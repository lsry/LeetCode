#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <array>
using std::array;

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        unordered_map<int, vector<int>> map;
        int pz = parents.size();
        int root = 0;
        for (int i = 0;i < pz;++i) {
            if (parents[i] != -1) {
                vector<int> cur = map[parents[i]];
                cur.push_back(i);
                map[parents[i]] = cur;
            } else {
                root = i;
            }
        }
        vector<array<int, 2>> count(pz);
        dfs(root, map, count);
        int res = 0;
        long long goal = 0;
        for (const array<int, 2> & c : count) {
            int tn = pz - c[0] - c[1] - 1;
            int ln = c[0];
            int rn = c[1];
            long long gn = tn;
            if (ln > 0) {
                gn = gn == 0 ? ln : gn * ln;
            }
            if (rn > 0) {
                gn = gn == 0 ? rn : gn * rn;
            }
            if (gn > goal) {
                goal = gn;
                res = 1;
            } else if (gn == goal) {
                res += 1;
            }
        }
        return res;
    }

private:
    int dfs(int root, unordered_map<int, vector<int>> &map, vector<array<int, 2>> &count) {
        vector<int> child = map[root];
        int cz = child.size();
        int ln = 0, rn = 0;
        if (cz >= 1) {
            ln = dfs(child[0], map, count);
        }
        if (cz >= 2) {
            rn = dfs(child[1], map, count);
        }
        array<int, 2> node;
        node[0] = ln;
        node[1] = rn;
        count[root] = node;
        return ln + rn + 1;
    }
};