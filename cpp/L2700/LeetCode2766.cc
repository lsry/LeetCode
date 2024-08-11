#include <map>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        std::map<int, int> stoneMap;
        for (int num : nums) {
            stoneMap[num] ++;
        }
        int N = moveFrom.size();
        for (int i = 0;i < N;++i) {
            int stone = stoneMap[moveFrom[i]];
            if (stone > 0) {
                stoneMap[moveFrom[i]] = 0;
                stoneMap[moveTo[i]] += stone;
            }
        }
        vector<int> r;
        r.reserve(stoneMap.size());
        for (auto it{stoneMap.begin()};it != stoneMap.end();++it) {
            if (it->second > 0) {
                r.push_back(it->first);
            }
        }
        return r;
    }
};