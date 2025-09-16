#include <array>
#include <string>
using std::string;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        std::array<bool, 26> flags{false};
        for (char c : brokenLetters) {
            flags[c - 'a'] = true;
        }
        int ans{0};
        int N = text.size();
        for (int i = 0;i < N;) {
            if (text[i] == ' ') {
                continue;
            }
            bool canType{true};
            int j{i};
            while (j < N && text[j] != ' ') {
                if (flags[text[j] - 'a']) {
                    canType = false;
                }
                ++j;
            }
            if (canType) {
                ++ans;
            }
            i = j + 1;
        }
        return ans;
    }
};