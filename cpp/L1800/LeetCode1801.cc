#include <vector>
using std::vector;

#include <queue>
#include <array>

class Solution {
    constexpr static unsigned long long int MOD = 1'000'000'007ULL;
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        auto f1 = [](std::pair<int, int> const &o1, std::pair<int, int> const &o2) {
            return o1.first >= o2.first;
        };
        auto f2 = [](std::pair<int, int> const &o1, std::pair<int, int> const &o2) {
            return o1.first <= o2.first;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(f1)> sells(f1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(f2)> buys(f2);
        for (vector<int> &order : orders) {
            int op = order[0], oa = order[1];
            if (order[2] == 0) {
                while (oa > 0 && !sells.empty() && sells.top().first <= op) {
                    std::pair<int, int> cur = sells.top();
                    sells.pop();
                    if (cur.second > oa) {
                        sells.push(std::make_pair(cur.first, cur.second - oa));
                        oa = 0;
                        break;
                    } else if (cur.second == oa) {
                        oa = 0;
                        break;
                    } else {
                        oa -= cur.second;
                    }
                }
                if (oa > 0) {
                    buys.push(std::make_pair(op, oa));
                }
            } else {
                while (oa > 0 && !buys.empty() && buys.top().first >= op) {
                    std::pair<int, int> cur = buys.top();
                    buys.pop();
                    if (cur.second > oa) {
                        buys.push(std::make_pair(cur.first, cur.second - oa));
                        oa = 0;
                        break;
                    } else if (cur.second == oa) {
                        oa = 0;
                        break;
                    } else {
                        oa -= cur.second;
                    }
                }
                if (oa > 0) {
                    sells.push(std::make_pair(op, oa));
                }
            }
        }
        unsigned long long int ans{0};
        while (!buys.empty()) {
            std::pair<int, int> p = buys.top();
            buys.pop();
            ans = (ans + p.second) % MOD;
        }
        while (!sells.empty()) {
            std::pair<int, int> p = sells.top();
            sells.pop();
            ans = (ans + p.second) % MOD;
        }
        return static_cast<int>(ans % MOD);
    }
};