#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        ans.reserve(spells.size());
        std::sort(potions.begin(), potions.end());
        for (int spell : spells) {
            long long div{success % spell == 0 ? success / spell : success / spell + 1};
            auto it{std::lower_bound(potions.begin(), potions.end(), div)};
            ans.push_back(potions.end() - it);
        }
        return ans;
    }
};