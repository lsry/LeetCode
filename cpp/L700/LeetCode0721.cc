#include <algorithm>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;
#include <string>
using std::string;

struct UnionFind {
    vector<int> ids, weights;

    UnionFind(int N): ids(N, 0), weights(N, 1) {
        for (int i = 0;i < N;++i) {
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
        if (weights[pid] >= weights[qid]) {
            ids[qid] = pid;
            weights[pid] += weights[qid];
        } else {
            ids[pid] = qid;
            weights[qid] += weights[pid];
        }
    }
};

class Solution {
    bool existEmail(vector<string> const &v1, vector<string> const &v2) {
        for (int i = 1;i < v1.size();++i) {
            for (int j = 1;j < v2.size();++j) {
                if (v1[i] == v2[j]) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int N = accounts.size();
        if (N <= 0) {
            return {};
        }
        UnionFind uf(N);
        for (int i = 0;i < N;++i) {
            for (int j = i + 1;j < N;++j) {
                if (existEmail(accounts[i], accounts[j])) {
                    uf.toUnion(i, j);
                }
            }
        }
        std::unordered_map<int, std::unordered_set<std::string_view>> mp;
        for (int i = 0;i < N;++i) {
            int id = uf.toFind(i);
            auto iter = mp.find(id);
            if (iter == mp.end()) {
                std::unordered_set<std::string_view> st;
                for (int j = 1;j < accounts[id].size();++j) {
                    st.emplace(accounts[id][j]);
                }
                mp[id] = st;
            }
            iter = mp.find(id);
            for (int j = 1;j < accounts[i].size();++j) {
                iter->second.emplace(accounts[i][j]);
            }
        }
        vector<vector<string>> res;
        for (auto const &[id, st] : mp) {
            res.push_back(vector<string>());
            res.back().push_back(accounts[id][0]);
            for (std::string_view sv : st) {
                res.back().emplace_back(string(sv.begin(), sv.end()));
            }
            std::sort(res.back().begin() + 1, res.back().end());
        }
        return res;
    }
};