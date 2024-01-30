#include <vector>
using std::vector;
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        std::sort(beans.begin(), beans.end());
        long long sum{std::accumulate(beans.begin(), beans.end(), 0LL)};
        long long res{sum};
        long long before{0LL};
        int bz = beans.size();
        for (int i = 0;i < bz;++i) {
            sum -= beans[i];
            long long after = sum - (static_cast<long long>(beans[i]) * (bz - i - 1));
            res = std::min(res, after + before);
            before += beans[i];
        }
        return res;
    }
};