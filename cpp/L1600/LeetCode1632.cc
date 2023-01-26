#include <vector>
using std::vector;
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <set>

class UnionFind
{
private:
    vector<int> ids, ranks;
public:
    UnionFind(int N) {
        for (int i = 0;i < N;++i) {
            ids.push_back(i);
            ranks.push_back(1);
        }
    }
    
    int to_find(int id) {
        while (id != ids[id]) {
            id = ids[id];
        }
        return id;
    }

    void to_union(int pid, int qid) {
        int p = to_find(pid);
        int q = to_find(qid);
        if (p == q) {
            return;
        }
        if (ranks[p] >= ranks[q]) {
            ids[q] = p;
            ranks[p] += 1;
        } else {
            ids[p] = q;
            ranks[q] += 1;
        }
    }
};


class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        UnionFind uf(M * N);
        for (int i = 0;i < M;++i) {
            std::unordered_map<int, vector<int>> map;
            for (int j = 0;j < N;++j) {
                map[matrix[i][j]].push_back(i * N + j);
            }
            for (auto &[k, v] : map) {
                std::size_t vz{v.size()};
                if (vz > 1) {
                    for (int a = 1;a < vz;++a) {
                        uf.to_union(v[0], v[a]);
                    }
                }
            }
        }
        for (int j = 0;j < N;++j) {
            std::unordered_map<int, vector<int>> map;
            for (int i = 0;i < M;++i) {
                map[matrix[i][j]].push_back(i * N + j);
            }
            for (auto &[k, v] : map) {
                std::size_t vz{v.size()};
                if (vz > 1) {
                    for (int a = 1;a < vz;++a) {
                        uf.to_union(v[0], v[a]);
                    }
                }
            }
        }
        std::vector<int> degree(M * N, 0);
        std::unordered_map<int, vector<int>> adjoins;
        for (int i = 0;i < M;++i) {
            std::unordered_map<int, int> map;
            for (int j = 0;j < N;++j) {
                map[matrix[i][j]] = i * N + j;
            }
            std::vector<int> sortArray;
            for (auto &[k, v] : map) {
                sortArray.push_back(v);
            }
            std::sort(sortArray.begin(), sortArray.end(), [&](int a, int b) {
                return matrix[a / N][a % N] <= matrix[b / N][b % N];
            });
            for (int x = 1;x < sortArray.size();++x) {
                int prev = uf.to_find(sortArray[x - 1]);
                int next = uf.to_find(sortArray[x]);
                degree[next] += 1;
                adjoins[prev].push_back(next);
            }
        }
        for (int j = 0;j < N;++j) {
            std::unordered_map<int, int> map;
            for (int i = 0;i < M;++i) {
                map[matrix[i][j]] = i * N + j;
            }
            std::vector<int> sortArray;
            for (auto &[k, v] : map) {
                sortArray.push_back(v);
            }
            std::sort(sortArray.begin(), sortArray.end(), [&](int a, int b) {
                return matrix[a / N][a % N] <= matrix[b / N][b % N];
            });
            for (int x = 1;x < sortArray.size();++x) {
                int prev = uf.to_find(sortArray[x - 1]);
                int next = uf.to_find(sortArray[x]);
                degree[next] += 1;
                adjoins[prev].push_back(next);
            }
        }
        
        std::set<int> st;
        std::vector<int> ranks(M * N, 0);
        for (int i = 0;i < M * N;++i) {
            int id = uf.to_find(i);
            st.emplace(id);
            ranks[id] = 1;
        }
        std::queue<int> q;
        for (int x : st) {
            if (degree[x] == 0) {
                q.push(x);
            }
        }
        while (!q.empty()) {
            int id = q.front();
            q.pop();
            for (int x : adjoins[id]) {
                degree[x] --;
                if (degree[x] == 0) {
                    q.push(x);
                }
                ranks[x] = std::max(ranks[x], ranks[id] + 1);
            }
        }
        vector<vector<int>> res(M, vector<int>(N, 0));
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                int id = uf.to_find(i * N + j);
                res[i][j] = ranks[id];
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> x{{-37,-50,-3,44},{-37,46,13,-32},{47,-42,-3,-40},{-17,-22,-39,24}};
    s.matrixRankTransform(x);
    return 0;
}
