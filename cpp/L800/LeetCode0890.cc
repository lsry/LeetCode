#include <vector>
using std::vector;

#include <string>
using std::string;

#include <array>
using std::array;

class Solution {
private:
    bool check(string const &word, string const &pattern) {
        std::array<array<int, 2>, 26> chars{{0}};
        std::size_t pz{pattern.size()};
        for (std::size_t i{0};i < pz;++i) {
            int pi = pattern[i] - 'a';
            int wi = word[i] - 'a';
            if (chars[pi][0] == 0) {
                if (chars[wi][1] == 1) {
                    return false;
                }
                chars[pi][0] = wi + 1;
                chars[wi][1] = 1;
            } else if (chars[pi][0] != wi + 1) {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string const & word : words) {
            if (check(word, pattern)) {
                res.push_back(word);
            }
        }
        return res;
    }
};