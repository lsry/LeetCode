#include <string>
using std::string;

class Solution {
    bool isYuan(char c) {
        return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u'
             || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }

    bool isFu(char c) {
        return isLetter(c) && !isYuan(c);
    }
public:
    bool isValid(string word) {
        bool yuan{false}, fu{false}, illegal{false};
        for (char c : word) {
            yuan |= isYuan(c);
            fu |= isFu(c);
            illegal |= !isLetter(c) && !isNumber(c);
        }
        return word.size() >= 3 && yuan && fu && !illegal;
    }
};