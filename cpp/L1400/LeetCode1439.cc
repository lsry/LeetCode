#include <vector>
using std::vector;
#include <unordered_set>
#include <algorithm>
#include <queue>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int M = mat.size(), N = mat[0].size();
        auto f{[&](vector<int> const &v1, vector<int> const &v2) {
            int s1{0}, s2{0};
            for (std::size_t i{0};i < M;++i) {
                s1 += mat[i][v1[i]];
                s2 += mat[i][v2[i]];
            }
            return s1 >= s2;
        }};
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(f)> pq(f);
        vector<int> first(M, 0);
        pq.push(first);
        auto hf{[](vector<int> const &v) {
            std::size_t x = 0;
            for (int vx : v) {
                x = x * 31 + vx;
            }
            return x;
        }};
        auto eqf{[&](vector<int> const &v1, vector<int> const &v2) {
            for (std::size_t i{0};i < M;++i) {
                if (v1[i] != v2[i]) {
                    return false;
                }
            }
            return true;
        }};
        std::unordered_set<vector<int>, decltype(hf), decltype(eqf)> st(2 * k, hf, eqf);
        st.emplace(first);
        for (int x = 0;x < k;++x) {
            vector<int> v{pq.top()};
            pq.pop();
            int s = 0;
            for (std::size_t i{0};i < M;++i) {
                s += mat[i][v[i]];
                if (v[i] < N - 1) {
                    vector<int> vt(v.begin(), v.end());
                    vt[i] = v[i] + 1;
                    int sz = st.size();
                    st.insert(vt);
                    if (st.size() != sz) {
                        pq.push(vt);
                    }
                }
            }
            if (x == k - 1) {
                return s;
            }
        }
        return -1;
    }
};