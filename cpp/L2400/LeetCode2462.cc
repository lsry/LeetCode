#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        auto f([](std::pair<int, int> const &a, std::pair<int, int> const &b) {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        });
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(f)> lq, rq;
        int N = costs.size();
        int left{candidates}, right = N - candidates - 1;
        for (int i = 0;i < candidates;++i) {
            lq.push(std::pair<int, int>(costs[i], i));
            rq.push(std::pair<int, int>(costs[N - i - 1], N - i - 1));
        }
        long long ans{0LL};
        if (left < N) {
            while (k > 0 && left <= right) {
                auto [lc, ld] = lq.top();
                auto [rc, rd]  = rq.top();
                if (lc < rc || (lc == rc && ld <= rd)) {
                    auto [cost, id] = lq.top();
                    lq.pop();
                    ans += cost;
                    lq.push(std::pair<int, int>(costs[left], left));
                    ++left;
                } else {
                    auto [cost, id] = rq.top();
                    rq.pop();
                    ans += cost;
                    rq.push(std::pair<int, int>(costs[right], right));
                    --right;
                }
                --k;
            }
        }
        // 小心左右重叠
        if (k > 0) {
            if (left == right + 1) {
                while (!rq.empty()) {
                    lq.push(rq.top());
                    rq.pop();
                }
            } else {
                while (left < N){
                    lq.push(std::pair<int, int>(costs[left], left));
                    ++left;
                }
            }
            while (k > 0) {
                auto [cost, id] = lq.top();
                lq.pop();
                ans += cost;
                --k;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ar{18,64,12,21,21,78,36,58,88,58,99,26,92,91,53,10,24,25,20,92,73,63,51,65,87,6,17,32,14,42,46,65,43,9,75};
    s.totalCost(ar, 13, 23);
}