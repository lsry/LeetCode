#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string r;
        for (string const &word : words) {
            int w{0};
            for (char const c : word) {
                w += weights[c - 'a'];
            }
            r.push_back(static_cast<char>((25 - w % 26) + 'a'));
        }
        return r;
    }
};
