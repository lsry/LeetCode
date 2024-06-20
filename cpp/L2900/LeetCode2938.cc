#include <string>
using std::string;

class Solution {
public:
    long long minimumSteps(string s) {
        long long int ans{0};
        int id{-1};
        int N = s.size();
        for (int i = 0;i < N;++i) {
            if (s[i] == '0') {
                ++id;
                ans += i - id;
            }
        }
        return ans;
    }
};