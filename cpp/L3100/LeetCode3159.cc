#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        std::unordered_map<int, int> mp;
        int idx{1};
        for (int i = 0;i < nums.size();++i) {
            if (nums[i] == x) {
                mp.emplace(idx, i);
                ++idx;
            }
        }      
        vector<int> r;
        for (int q : queries) {
            auto it{mp.find(q)};
            if (it != mp.end()) {
                r.push_back(it->second);
            } else {
                r.push_back(-1);
            }
        }
        return r;
    }
};