#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        unordered_map<int, int> map;
        for (int i = 1;i * 5 <= n;++i) {
            if (map.find(i) != map.end()) {
                map[i * 5] = map[i] + 1;
            } else {
                map[i * 5] = 1;
            }
            ans += map[i * 5];
        }
        return ans;
    }
};