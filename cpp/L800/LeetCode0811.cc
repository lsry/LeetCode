#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        std::unordered_map<string, int> map;
        for (string const &cpdomain : cpdomains) {
            int count = 0;
            std::size_t dz{cpdomain.size()};
            std::size_t i{0};
            while (i < dz && cpdomain[i] != ' ') {
                count = count * 10 + (cpdomain[i] - '0');
                ++i;
            }
            for (;i + 1 < dz;++i) {
                if (cpdomain[i] == ' ' || cpdomain[i] == '.') {
                    string domain = cpdomain.substr(i + 1);
                    map[domain] += count;
                }
            }
        }
        vector<string> res;
        for (std::pair<string, int> const &entity : map) {
            res.push_back(std::to_string(entity.second) + " " + entity.first);
        }
        return res;
    }
};