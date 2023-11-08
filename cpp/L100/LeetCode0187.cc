#include <unordered_map>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<string> findRepeatedDnaSequencesStringMap(string s) {
        std::unordered_map<string, int> cnt;
        int sz = s.size();
        for (int i = 0;i + 10 <= sz;++i) {
            cnt[s.substr(i, 10)] += 1;
        }
        vector<string> res;
        for (auto const &[k, v] : cnt) {
            if (v > 1) {
                res.push_back(k);
            }
        }
        return res;
    }

    constexpr static int MOD{0xFFFFF};

    vector<string> findRepeatedDnaSequences(string s) {
        std::unordered_map<int, int> cnt;
        int sz = s.size();
        int num{0};
        vector<string> res;
        for (int i{0},j{0};j < sz;++j) {
            num = num << 2;
            if (s[j] == 'A') {
                num += 0;
            } else if (s[j] == 'C') {
                num += 1;
            } else if (s[j] == 'G') {
                num += 2;
            } else if (s[j] == 'T') {
                num += 3;
            }
            if (j - i + 1 > 10) {
                ++i;
            }
            if (j - i + 1 == 10) {
                cnt[num & MOD] += 1;
                if (cnt[num & MOD] == 2) {
                    res.emplace_back(s.substr(i, 10));
                }
            }
        }
        return res;
    }

};