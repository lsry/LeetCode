#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
#include <numeric>

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        return std::accumulate(words.begin(), words.end(), 0, [&](int x, string const &word){
            if (pref.size() > word.size()) {
                return x;
            }
            for (std::size_t i{0};i < pref.size();++i) {
                if (word[i] != pref[i]) {
                    return x;
                }
            }
            return x + 1;
        });
    }
};