#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
#include <numeric>

class Solution {
    static int getValue(string const &str) {
        int value{0};
        for (char const &c : str) {
            if (c >= '0' && c <= '9') {
                value = value * 10 + (c - '0');
            } else {
                return str.size();
            }
        }
        return value;
    }
public:
    int maximumValue(vector<string>& strs) {
        string s =  *std::max_element(strs.begin(), strs.end(), [](string const &s1, string const &s2) {
            return getValue(s1) < getValue(s2);
        });
        return getValue(s);
    }
};