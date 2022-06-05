#include <string>
using std::string;

#include <vector>
using std::vector;

#include <array>
#include <queue>
#include <algorithm>

class Solution {
public:
    string alienOrder(vector<string>& words) {
        std::array<std::vector<char>, 26> suffix;
        std::array<int, 26> degIns{{0}}; 
        std::array<bool, 26> flags{{false}};
        std::size_t wz{words.size()};
        for (std::size_t i{0};i < wz;++i) {
            for (char const c : words[i]) {
                flags[c - 'a'] = true;
            }
            for (std::size_t j{i + 1};j < wz;++j) {
                std::size_t minLen = std::min(words[i].size(), words[j].size());
                std::size_t k{0};
                while (k < minLen && words[i][k] == words[j][k]) {
                    ++k;
                }
                if (k < minLen) {
                    int p1 = words[i][k] - 'a';
                    int p2 = words[j][k] - 'a';
                    if (std::find(suffix[p2].begin(), suffix[p2].end(), words[i][k]) != suffix[p2].end()) {
                        return "";
                    }
                    if (std::find(suffix[p1].begin(), suffix[p1].end(), words[j][k]) == suffix[p1].end()) {
                        suffix[p1].push_back(words[j][k]);
                        degIns[p2]++;
                    }
                } else if (words[i].size() > words[j].size()) {
                    return "";
                }
            }
        }
        std::queue<int> qu;
        for (int i = 0;i < 26;++i) {
            if (degIns[i] == 0 && flags[i]) {
                qu.push(i);
            }
        }
        std::string res;
        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            res.push_back((char)(cur + 'a'));
            flags[cur] = false;
            for (char c : suffix[cur]) {
                int p = c - 'a';
                degIns[p]--;
                if (degIns[p] == 0) {
                    qu.push(p);
                }
            }
        }
        for (int i = 0;i < 26;++i) {
            if (flags[i]) {
                res.push_back((char)(i + 'a'));
            }
        }
        return res;
    }
};