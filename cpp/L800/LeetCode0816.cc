#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
private:
    std::size_t sz{0};

    void parse(string const &s, std::size_t f, std::size_t e, vector<string> &nums) {
        bool h0{s[f] == '0'}, t0{s[e] == '0'};
        if (f != e && h0 && t0) {
            return;
        }
        if (f == e) {
            nums.push_back(s.substr(f, 1));
            return;
        }
        if (!h0) {
            nums.push_back(s.substr(f, e - f + 1));
        }
        if (!t0) {
            for (std::size_t i{f + 1};i <= e;++i) {
                if (i > f + 1 && s[f] == '0') {
                    break;
                }
                nums.push_back(s.substr(f, i - f) + "." + s.substr(i, e - i + 1));
            }
        }
    }

    void merge(vector<string> const &n1, vector<string> const &n2, vector<string> &nr) {
        for (string const &s1 : n1) {
            for (string const &s2 : n2) {
                nr.push_back("(" + s1 + ", " + s2 + ")");
            }
        }
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        sz = s.size();
        if (sz < 4) {
            return {};
        }
        vector<string> n1, n2, nr;
        if (s[1] == '0') {
            n1.push_back("0");
            parse(s, 2, sz - 2, n2);
            merge(n1, n2, nr);
            n1[0].push_back('.');
            for (std::size_t i{2};i < sz - 2;++i) {
                n1[0].push_back(s[i]);
                if (s[i] != '0') {
                    n2.clear();
                    parse(s, i + 1, sz - 2, n2);
                    merge(n1, n2, nr);
                }
            }
        } else {
            for (std::size_t i{1};i < sz - 2;++i) {
                n1.clear();
                n2.clear();
                parse(s, 1, i, n1);
                parse(s, i + 1, sz - 2, n2);
                merge(n1, n2, nr);
            }
        }
        return nr;
    }
};