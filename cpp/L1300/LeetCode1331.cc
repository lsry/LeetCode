#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ai;
        std::size_t az{arr.size()};
        for (int i = 0;i < az;++i) {
            ai.push_back(i);
        }
        std::stable_sort(ai.begin(), ai.end(), [&](int x, int y) -> bool {
            return arr[x] < arr[y];
        });
        vector<int> res(az, 0);
        int idx = 1;
        for (int i = 0;i < az;++i) {
            if (i == 0 || arr[ai[i]] > arr[ai[i - 1]]) {
                ++idx;
                res[ai[i]] = idx;
            } else if (arr[ai[i]] == arr[ai[i - 1]]) {
                res[ai[i]] = idx;
            }
        }
        return res;
    }
};