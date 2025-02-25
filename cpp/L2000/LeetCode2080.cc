#include <algorithm>
#include <unordered_map>
#include <vector>
using std::vector;

class RangeFreqQuery {
    std::unordered_map<int, vector<int>> mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0;i < arr.size();++i) {
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto fi{std::lower_bound(mp[value].begin(), mp[value].end(), left)};
        if (fi == mp[value].end() || *fi > right) {
            return 0;
        }
        auto ei{std::upper_bound(mp[value].begin(), mp[value].end(), right)};
        return ei - fi;
    }
};