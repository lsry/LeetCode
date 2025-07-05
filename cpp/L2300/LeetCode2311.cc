#include <string>
using std::string;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len{0};
        for (char c : s) {
            if (c == '0') {
                ++len;
            }
        }  
        int digit{0};   
        unsigned long long int sum{0ULL}; 
        for (auto it{s.rbegin()};it != s.rend() && digit < 30;++it) {
            if (*it == '1') {
                unsigned long long int cur{1uLL << digit};
                sum += cur;
                if (sum <= k) {
                    ++len;
                } else {
                    break;
                }
            }
            ++digit;
        }
        return len;
    }
};