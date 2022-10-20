#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        std::size_t tz{target.size()};
        for (std::size_t i{0}, j{1};i < tz;++i) {
            while (j < target[i]) {
                res.push_back("Push");
                res.push_back("Pop");
                ++j;
            }
            res.push_back("Push");
            ++j;
        }
        return res;
    }
};