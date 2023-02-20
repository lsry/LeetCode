#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        std::unordered_map<int, int> map;
        int hz = hours.size();
        int sum{0}, ans{0};
        for (int i = 0;i < hz;++i) {
            if (hours[i] > 8) {
                ans = std::max(ans, 1);
                sum += 1;
            } else {
                sum -= 1;
            }
            if (sum > 0) {
                ans = std::max(ans, i + 1);
            } else {
                auto it{map.find(sum - 1)};
                if (it != map.end()) {
                    ans = std::max(ans, i - it->second);
                }
            }
            if (map.find(sum) == map.end()) {
                map[sum] = i;
            }
        }
        return ans;
    }
};