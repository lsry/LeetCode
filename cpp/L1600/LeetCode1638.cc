#include <string>
using std::string;
#include <vector>

class Solution {
public:
    int countSubstrings(string s, string t) {
        std::size_t sz{s.size()}, tz{t.size()};
        std::vector<int> cnt(tz + 1, 0), same(tz + 1, 0);
        std::vector<int> cnt2(tz + 1, 0), same2(tz + 1, 0);
        std::vector<int> &cntt = cnt, &samet = same;
        std::vector<int> &cntt2 = cnt2, &samet2 = same2;
        int ans{0};
        for (int i{1};i <= sz;++i) {
            std::fill(cntt2.begin(), cntt2.end(), 0);
            std::fill(samet2.begin(), samet2.end(), 0);
            for (int j{1};j <= tz;++j) {
                if (s[i - 1] == t[j - 1]) {
                    cntt2[j] = cntt[j - 1];
                    ans += cntt2[j];
                    samet2[j] = samet[j - 1] + 1;
                } else {
                    cntt2[j] = samet[j - 1] + 1;
                    samet2[j] = 0;
                    ans += cntt2[j];
                }
            }
            std::vector<int> &cntt3 = cntt, &samet3 = samet;
            cntt = cntt2;
            samet = samet2;
            cntt2 = cntt3;
            samet2 = samet3;
        }
        return ans;
    }
};