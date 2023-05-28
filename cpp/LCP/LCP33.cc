#include <vector>
using std::vector;
#include <limits>
#include <queue>

class Solution {
    int count(int bx, int vx) {
        if (vx == 0) {
            return 0;
        }
        if (bx == 0) {
            return std::numeric_limits<int>::max() / 1000;
        }
        return vx % bx == 0 ? vx / bx : vx / bx + 1;
    }
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        auto f{[&](int x, int y){
            int rx = count(bucket[x], vat[x]);
            int ry = count(bucket[y], vat[y]);
            return rx < ry;
        }};
        std::priority_queue<int, vector<int>, decltype(f)> pq(f);
        int N = bucket.size();
        for (int i = 0;i < N;++i) {
            pq.push(i);
        }
        int step = std::numeric_limits<int>::max();
        for (int add{0};add < step;++add) {
            int cnt{0};
            for (int i = 0;i < N;++i) {
                cnt = std::max(cnt, count(bucket[i], vat[i]));
            }
            step = std::min(step, cnt + add);
            if (pq.empty()) {
                break;
            }
            int x = pq.top();
            pq.pop();
            if (bucket[x] < vat[x]) {
                bucket[x] += 1;
                pq.push(x);
            }
        }
        return step;
    }
};