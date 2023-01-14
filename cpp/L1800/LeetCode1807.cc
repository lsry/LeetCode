#include <vector>
using std::vector;
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for (vector<string> &know : knowledge) {
            map.insert(std::make_pair(know[0], know[1]));
        }
        string res;
        std::size_t sz{s.size()};
        for (std::size_t i{0};i < sz;++i) {
            if (s[i] == '(') {
                std::size_t j{i + 1};
                while (j < sz && s[j] != ')') {
                    ++j;
                }
                string key{s.substr(i + 1, j - i - 1)};
                auto it = map.find(key);
                if (it == map.end()) {
                    res.push_back('?');
                } else {
                    res.append(it->second);
                }
                i = j;
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};