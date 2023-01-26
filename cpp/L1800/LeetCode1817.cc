#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        std::sort(logs.begin(), logs.end(), [](vector<int> const &loga, vector<int> const &logb){
            return loga[0] == logb[0] ? loga[1] <= logb[1] : loga[0] < logb[0];
        });
        vector<int> res(k, 0);
        std::size_t lz{logs.size()};
        for (std::size_t i{0};i < lz;) {
            int count{1};
            std::size_t j{i + 1};
            while (j < lz && logs[j][0] == logs[i][0]) {
                if (logs[j][1] != logs[j - 1][1]) {
                    ++count;
                }
                ++j;
            }
            if (count > 0 && count <= k) {
                res[count - 1] += 1;
            }
            i = j;
        }
        return res;
    }
};