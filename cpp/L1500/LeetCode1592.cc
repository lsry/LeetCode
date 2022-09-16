#include <string>
using std::string;

#include <vector>

class Solution {
public:
    string reorderSpaces(string text) {
        int space = 0;
        std::string word;
        std::vector<string> words;
        std::size_t tz{text.size()};
        for (std::size_t i{0};i <= tz;++i) {
            if (i == tz) {
                if (!word.empty()) {
                    words.push_back(word);
                }
            } else if (text[i] == ' ') {
                space++;
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word.push_back(text[i]);
            }
        }
        if (words.empty() || space == 0) {
            return text;
        } else if (words.size() == 1) {
            return words[0] + string(space, ' ');
        } else {
            int wz = words.size();
            int space_word = space / (wz - 1);
            string space_str(space_word, ' ');
            int space_left = space % (wz - 1);
            string res;
            for (std::size_t i{0};i < wz;++i) {
                res.append(words[i]);
                if (i != wz - 1) {
                    res.append(space_str);
                }
            }
            if (space_left != 0) {
                res.append(string(space_left, ' '));
            }
            return res;
        }
    }
};