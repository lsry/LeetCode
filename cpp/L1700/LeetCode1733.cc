#include <limits>
#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
    bool canCantact(std::unordered_set<int> const &s1, std::unordered_set<int> const &s2) {
        for (int x : s1) {
            if (s2.contains(x)) {
                return true;
            }
        }
        return false;
    }
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int ans{std::numeric_limits<int>::max()};
        vector<std::unordered_set<int>> pl;
        for (vector<int> const &l : languages) {
            pl.emplace_back(std::unordered_set<int>(l.begin(), l.end()));
        }
        vector<vector<int>> notContact;
        for (vector<int> const &f : friendships) {
            if (canCantact(pl[f[0] - 1], pl[f[1] - 1])) {
                continue;
            }
            notContact.emplace_back(f);
        }
        for (int l = 1;l <= n;++l) {
            int count{0};
            vector<int> flags(languages.size(), 0);
            for (vector<int> const &f : notContact) {
                if (!pl[f[0] - 1].contains(l)) {
                    flags[f[0] - 1] = 1;
                }
                if (!pl[f[1] - 1].contains(l)) {
                    flags[f[1] - 1] = 1;
                }
            }
            for (int b : flags) {
                if (b == 1) {
                    ++count;
                }
            }
            ans = std::min(ans, count);
        }
        return ans;
    }
};