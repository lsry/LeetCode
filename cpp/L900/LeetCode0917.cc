#include <string>
using std::string;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            while (low < high && !isLetter(s[low])) {
                ++low;
            }
            while (low < high && !isLetter(s[high])) {
                --high;
            }
            if (low < high) {
                char c = s[low];
                s[low] = s[high];
                s[high] = c;
            }
            --high;
            ++low;
        }
        return s;
    }

private:
    bool isLetter(char c) {
        return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
    }
};