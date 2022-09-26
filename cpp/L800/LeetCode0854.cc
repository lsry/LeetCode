#include <string>
using std::string;
#include <unordered_map>

class Solution {
private:
    std::size_t sz{0};
    std::unordered_map<string, int> map;
    void swap(string &s1, std::size_t id1, std::size_t id2) {
        char c = s1[id1];
        s1[id1] = s1[id2];
        s1[id2] = c;
    }
    int dfs(string &s1, string &s2, std::size_t id) {
        if (id >= sz) {
            return 0;
        }
        if (map.find(s1) != map.end()) {
            return map[s1];
        }
        if (s1[id] == s2[id]) {
            return dfs(s1, s2, id + 1);
        }
        int r = sz;
        for (std::size_t i{id + 1};i < sz;++i) {
            if (s1[i] != s2[id]) {
                continue;
            }
            swap(s1, id, i);
            r = std::min(dfs(s1, s2, id + 1), r);
            swap(s1, id, i);
        }
        map[s1] = r + 1;
        return r + 1;
    }
public:
    int kSimilarity(string s1, string s2) {
        sz = s1.size();
        return dfs(s1, s2, 0);
    }
};