#include <vector>
using std::vector;
#include <queue>
#include <unordered_set>

struct Pos
{
    int xh, yh, xt, yt, dis;
    Pos(int xh1, int yh1, int xt1, int yt1, int dis1)
        :xh(xh1), yh(yh1), xt(xt1), yt(yt1), dis(dis1) {}
};

class Solution {
    unsigned long long int hash(unsigned long long int x1, unsigned long long int y1, 
                                unsigned long long int x2, unsigned long long int y2) {
        return x1 * 1000'000'000 + y1 * 1000000 + x2 * 1000 + y2;
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        std::queue<Pos> q;
        std::unordered_set<unsigned long long int> st;
        q.push(Pos(0, 1, 0, 0, 0));
        while (!q.empty()) {
            Pos p{q.front()};
            q.pop();
            if (p.xh == n - 1 && p.yh == n - 1 && p.xt == n - 1 && p.yt == n - 2) {
                return p.dis;
            }
            if (p.xh == p.xt) { // 水平
                if (p.yh + 1 < n && grid[p.xh][p.yh + 1] == 0) { // 右邊移動一格
                    unsigned long long int h{hash(p.xh, p.yh + 1, p.xt, p.yt + 1)};
                    if (st.find(h) == st.end()) {
                        q.push(Pos(p.xh, p.yh + 1, p.xt, p.yt + 1, p.dis + 1));
                        st.emplace(h);
                    }
                }
                if (p.xh + 1 < n && p.xt + 1 < n && grid[p.xh + 1][p.yh] == 0 && grid[p.xt + 1][p.yt] == 0) {
                    unsigned long long int h{hash(p.xh + 1, p.yh, p.xt + 1, p.yt)};
                    if (st.find(h) == st.end()) {
                        q.push(Pos(p.xh + 1, p.yh, p.xt + 1, p.yt, p.dis + 1));
                        st.emplace(h);
                    }
                    h = hash(p.xt + 1, p.yt, p.xt, p.yt);
                    if (st.find(h) == st.end()) {
                        q.push(Pos(p.xt + 1, p.yt, p.xt, p.yt, p.dis + 1));
                        st.emplace(h);
                    }
                }
            } else if (p.yh == p.yt) { // 豎直
                if (p.xh + 1 < n && grid[p.xh + 1][p.yh] == 0) {
                    unsigned long long int h{hash(p.xh + 1, p.yh, p.xt + 1, p.yt)};
                    if (st.find(h) == st.end()) {
                        st.emplace(h);
                        q.push(Pos(p.xh + 1, p.yh, p.xt + 1, p.yt, p.dis + 1));
                    }
                }
                if (p.yh + 1 < n && p.yt + 1 < n && grid[p.xh][p.yh + 1] == 0 && grid[p.xt][p.yt + 1] == 0) {
                    unsigned long long int h{hash(p.xh, p.yh + 1, p.xt, p.yt + 1)};
                    if (st.find(h) == st.end()) {
                        st.emplace(h);
                        q.push(Pos(p.xh, p.yh + 1, p.xt, p.yt + 1, p.dis + 1));
                    }
                    h = hash(p.xt, p.yt + 1, p.xt, p.yt);
                    if (st.find(h) == st.end()) {
                        st.emplace(h);
                        q.push(Pos(p.xt, p.yt + 1, p.xt, p.yt, p.dis + 1));
                    }
                }
            }
        }
        return -1;
    }
};