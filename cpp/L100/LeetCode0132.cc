#include <limits>
#include <string>
using std::string;
#include <vector>

class Solution {
    bool isPalindrome(string const &s, int left, int right) {
        for (;left < right;++left, --right) {
            if (s[left] != s[right]) {
                return false;
            }
        }
        return true;
    }
    int cutStep(string const &s, int index, std::vector<int> &mem) {
        if (index >= s.size()) {
            return 0;
        } else if (mem[index] != -1) {
            return mem[index];
        } else {
            int ans{std::numeric_limits<int>::max()};
            for (int i = index;i < s.size();++i) {
                if (isPalindrome(s, index, i)) {
                    int step = cutStep(s, i + 1, mem);
                    ans = std::min(ans, step + 1);
                }
            }
            mem[index] = ans;
            return ans;
        }
    }
public:
    int minCut(string s) {
        std::vector<int> mem(s.size(), -1);
        cutStep(s, 0, mem);
        return mem[0] - 1;
    }
};