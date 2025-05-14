#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        std::unordered_map<int, int> mp;
        int ans{0};
        for (vector<int> const &d : dominoes) {
            int x = d[0];
            int y = d[1];
            if (x > y) {
                std::swap(x, y);
            }
            int xy = x * 10 + y;
            ans += mp[xy];
            mp[xy] += 1;
        }
        return ans;
    }
};