#include <numeric>
#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        std::size_t N{arr.size()};
        vector<int> ai(N, 0);
        std::iota(ai.begin(), ai.end(), 0);
        std::sort(ai.begin(), ai.end(), [&](int x, int y) -> bool {
            return arr[x] < arr[y];
        });
        vector<int> res(N, 0);
        for (int i = 0, idx = 0;i < N;++i) {
            if (i > 0 && arr[ai[i]] == arr[ai[i - 1]]) {
                res[ai[i]] = idx;
            } else {
                ++idx;
                res[ai[i]] = idx;
            }
        }
        return res;
    }
};
