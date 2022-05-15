#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> res;
        std::size_t sz{s.size()};
        int low = 0, high = sz;
        for (std::size_t i{0};i < sz;++i) {
            if (s[i] == 'I') {
                res.push_back(low);
                ++low;
            } else {
                res.push_back(high);
                --high;
            }
        }
        res.push_back(low);
        return res;
    }
};