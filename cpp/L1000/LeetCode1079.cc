#include <string>
using std::string;
#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
    void trace(string const &key, int index, std::vector<bool> &flags, string &str, std::unordered_set<string> &paths) {
        int kz = key.size();
        if (index >= kz) {
            paths.emplace(str);
            return;
        }
        for (int i = 0;i < kz;++i) {
            if (flags[i] == false) {
                flags[i] = true;
                str.push_back(key[i]);
                trace(key, index + 1, flags, str, paths);
                str.pop_back();
                flags[i] = false;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        std::stable_sort(tiles.begin(), tiles.end());
        std::unordered_set<string> res;
        std::unordered_set<string> keys;
        int tn = tiles.size();
        for (int i = 1;i < (1 << tn);++i) {
            string key;
            for (int j = 0;j < tn;++j) {
                if (((i >> j) & 1) != 0) {
                    key.push_back(tiles[j]);
                }
            }
            int kz = keys.size();
            keys.emplace(key);
            if (keys.size() > kz) {
                std::vector<bool> flags(key.size(), false);
                string s;
                trace(key, 0, flags, s, res);
            }
        }
        return res.size();
    }
};