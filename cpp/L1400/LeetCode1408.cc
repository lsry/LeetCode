#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        std::stable_sort(words.begin(), words.end(), [](string const &s1, string const &s2) -> bool {
            return s1.size() < s2.size();
        });
        vector<string> res;
        for (std::size_t i{0};i < words.size();++i) {
            for (std::size_t j = i + 1; j < words.size();++j) {
                if (words[i].size() < words[j].size() && words[j].find(words[i]) != std::string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};