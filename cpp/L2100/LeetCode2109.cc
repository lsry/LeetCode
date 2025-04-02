#include <cstddef>
#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        std::size_t N{s.size()}, SN{spaces.size()};
        string r;
        for (std::size_t i{0}, j{0};i < N;++i) {
            if (j < SN && spaces[j] == i) {
                r.push_back(' ');
                ++j;
            }
            r.push_back(s[i]);
        }      
        return r;
    }
};