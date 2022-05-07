#include <vector>
using std::vector;

#include <string>
using std::string;

#include <tuple>
using std::tuple;

#include <algorithm>

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<int> nums;
        vector<tuple<int, string, string>> alphas;
        std::size_t sz = logs.size();
        for (std::size_t i{0};i < sz;++i) {
            string log = logs[i];
            std::size_t j{0}, lz{log.size()};
            while (j < lz && log[j] != ' ') {
                ++j;
            }
            if (isNums(log, j + 1)) {
                nums.push_back(i);
            } else {
                alphas.push_back({i, log.substr(0, j), log.substr(j + 1)});
            }
        }
        vector<string> res;
        std::stable_sort(alphas.begin(), alphas.end(), [](const auto &t1, const auto &t2){
            string s1 = std::get<2>(t1);
            string s2 = std::get<2>(t2);
            if (s1 == s2) {
                return std::get<1>(t1) <= std::get<1>(t2);
            } else {
                return s1 < s2;
            }
        });
        for (const auto &alpha : alphas) {
            res.push_back(logs[std::get<0>(alpha)]);
        }
        for (const int &num : nums) {
            res.push_back(logs[num]);
        }
        return res;
    }

    bool isNums(string const &str, std::size_t fi) {
        return str[fi] >= '0' && str[fi] <= '9';
    }
};