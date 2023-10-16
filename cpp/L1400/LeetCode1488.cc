#include <set>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        std::unordered_map<int, int> lakes;
        std::set<int> sunnys;
        int rz = rains.size();
        vector<int> ans(rz, 1);
        for (int i = 0;i < rz;++i) {
            if (rains[i] == 0) {
               sunnys.emplace(i);
               continue;
            } 
            auto it{lakes.find(rains[i])};
            if (it == lakes.end()) {
                lakes[rains[i]] = i;
                ans[i] = -1;
            } else if (sunnys.empty()) {
                return {};
            } else {
                auto up{sunnys.upper_bound(it->second)};
                if (up == sunnys.end()) {
                    return {};
                }
                int day = *up;
                sunnys.erase(up);
                ans[day] = rains[i];
                lakes[rains[i]] = i;
                ans[i] = -1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> r{1,2,3,4,5};
    s.avoidFlood(r);
}