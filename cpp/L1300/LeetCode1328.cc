#include <string>
using std::string;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() < 2) {
            return "";
        }
        bool replace{false};
        for (int left{0}, right = palindrome.size() - 1;left < right;++left, --right) {
            if (palindrome[left] != 'a') {
                palindrome[left] = 'a';
                replace = true;
                break;
            }
        }
        if (!replace) {
            int RN = (palindrome.size() - 1) / 2 + 1;
            for (int right = palindrome.size() - 1;right >= RN;--right) {
                if (palindrome[right] == 'a') {
                    palindrome[right] = 'b';
                    replace = true;
                    break;
                }
            }
        }
        return replace ? palindrome : "";
    }
};