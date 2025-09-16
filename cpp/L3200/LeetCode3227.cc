#include <string>
using std::string;

class Solution {
    bool isVowl(char c) {
        c = std::tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    bool doesAliceWin(string s) {
        int count{0};
        for (char c : s) {
            if (isVowl(c)) {
                ++count;
            }
        }  
        return count != 0;
    }
};