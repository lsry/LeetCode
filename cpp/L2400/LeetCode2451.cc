#include <vector>
using std::vector;
#include <string>
using std::string;
#include <unordered_map>

class Solution {
public:
    string oddString(vector<string>& words) {
        std::size_t wz{words[0].size()}, wwz{words.size()};
        std::unordered_map<int, std::pair<int, int>> map;
        for (std::size_t i{0};i < wz - 1;++i) {
            for (std::size_t j{0};j < wwz;++j) {
                int diff = words[j][i + 1] - words[j][i];
                auto mit = map.find(diff);
                if (mit == map.end()) {
                    map.emplace(std::make_pair(diff, std::make_pair(j, 1)));
                } else {
                    mit->second.second += 1;
                }
            }
            for (auto &[diff, pp] : map) {
                if (pp.second == 1) {
                    return words[pp.first];
                }
            }
            map.clear();
        }
        return "";
    }
};