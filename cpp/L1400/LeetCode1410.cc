#include <cctype>
#include <string>
#include <unordered_map>
using std::string;

class Solution {
    std::unordered_map<string, char> signs;
public:
    Solution() {
        signs["quot"] = '"';
        signs["apos"] = '\'';
        signs["amp"] = '&';
        signs["gt"] = '>';
        signs["lt"] = '<';
        signs["frasl"] = '/';
    }
    string entityParser(string text) {
        string res;
        std::size_t tz{text.size()};
        for (std::size_t i{0};i < tz;++i) {
            if (text[i] == '&' && i + 1 < tz && std::islower(text[i + 1])) {
                int j = i + 1;
                string r;
                while (j < tz && text[j] != ';') {
                    r.push_back(text[j]);
                    ++j;
                }
                if (j < tz && text[j] == ';' && signs.find(r) != signs.end()) {
                    res.push_back(signs[r]);
                    i = j;
                } else {
                    res.push_back(text[i]);
                }
            } else {
                res.push_back(text[i]);
            }
        }
        return res;
    }
};