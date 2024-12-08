#include <string>
using std::string;

#include <vector>
using std::vector;

#include <unordered_map>

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::unordered_map<string, int> outs;
        for (vector<string> const &path : paths) {
            outs[path[0]] += 1;
            if (outs.find(path[1]) == outs.end()) {
                outs[path[1]] = 0;
            }
        }
        for (auto const &[k, v] : outs) {
            if (v == 0) {
                return k;
            }
        }
        return "";
    }
};