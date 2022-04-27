#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        int sz = s.size();
        int low = 0, high = 0;
        while (low >= 0 && s[low] != c) {
            --low;
        }
        while (high < sz && s[high] != c) {
            ++high;
        }
        for (int i = 0;i < sz;++i) {
           if (i > high) {
                low = high;
                ++high;
                while (high < sz && s[high] != c) {
                   ++high;
                }
           }
           if (low >= 0 && high < sz) {
               res.push_back(std::min(i - low, high - i));
           } else if (low >= 0) {
               res.push_back(i - low);
           } else {
               res.push_back(high - i);
           }
        }
        return res;
    }
};