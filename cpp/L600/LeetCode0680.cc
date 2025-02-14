#include <string>
using std::string;

class Solution {
    bool checkPalindrome(string const &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int N = s.size();
        for (int i = 0, j = N - 1;i < j;++i, --j) {
            if (s[i] != s[j]) {
                return (i + 1 < N && s[i + 1] == s[j] && checkPalindrome(s, i + 1, j)) 
                    || (j - 1 >= 0 && s[i] == s[j - 1] && checkPalindrome(s, i, j - 1));
            }
        }
        return true;
    }
};