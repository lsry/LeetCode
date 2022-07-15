#include <vector>
using std::vector;

#include <algorithm>
#include <numeric>

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::stable_sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int diff = std::numeric_limits<int>::max();
        std::size_t az{arr.size()};
        for (std::size_t i{0};i + 1 < az;++i) {
            int af = arr[i + 1] - arr[i];
            if (af < diff) {
                diff = af;
                res.clear();
                res.push_back({arr[i], arr[i + 1]});
            } else if (af == diff) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};