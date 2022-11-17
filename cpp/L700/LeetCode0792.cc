#include <vector>
using std::vector;

#include <string>
using std::string;

#include <set>

class Solution {
private:
    bool containWord(vector<std::set<int>> &ci, string const &word) {
        int initialId{-1};
        for (char const c : word) {
            int cid{c - 'a'};
            auto it = ci[cid].upper_bound(initialId);
            if (it == ci[cid].end()) {
                return false;
            }
            initialId = *it;
        }
        return true;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<std::set<int>> ci(26, std::set<int>());
        for (std::size_t i{0};i < s.size();++i) {
            int id{s[i] - 'a'};
            ci[id].emplace(i);
        }
        int ans{0};
        for (string const &word : words) {
            if (containWord(ci, word)) {
                ++ans;
            }
        }
        return ans;
    }
};