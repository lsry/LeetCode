#include <vector>
using std::vector;
#include <string>
using std::string;
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        std::unordered_map<string, std::vector<std::pair<int, int>>> map;
        std::size_t kz{keyName.size()};
        for (std::size_t i{0};i < kz;++i) {
            int hour{std::stoi(keyTime[i].substr(0, 2))};
            int minute{std::stoi(keyTime[i].substr(3, 2))};
            map[keyName[i]].push_back(std::pair<int, int>(hour,minute));
        }
        std::unordered_set<string> st;
        for (auto &[name, times] : map) {
            std::sort(times.begin(), times.end(), [](auto const &t1, auto const &t2){
                return t1.first == t2.first ? t1.second < t2.second : t1.first < t2.first;
            });
            std::size_t tz{times.size()};
            for (std::size_t i{2};i < tz;++i) {
                if (times[i].first == times[i - 2].first || (times[i].first != 0 && times[i - 2].first + 1 == times[i].first
                    && times[i - 2].second - times[i].second >= 0)) {
                        st.emplace(name);
                    }
            }
        }
        vector<string> res(st.begin(), st.end());
        std::sort(res.begin(), res.end());
        return res;
    }
};