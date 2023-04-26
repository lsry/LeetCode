#include <vector>
#include <string>
using std::string;
#include <string_view>
#include <algorithm>

class Solution {
public:
    string lastSubstring(string s) {
        auto v{std::max_element(s.begin(), s.end())};
        if (v == s.end() || *v == 'a') {
            return s;
        }
        std::size_t sz{s.size()};
        std::vector<std::string_view> subs;
        std::string_view stv{s};
        for (std::size_t i{0};i < sz;++i) {
            if (s[i] == *v) {
                subs.push_back(stv.substr(i));
            }
        }
        std::string_view xv{*std::max_element(subs.begin(), subs.end())};
        return {xv.data(), xv.size()};
    }
};