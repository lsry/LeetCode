#include <string>
using std::string;

class Solution {
public:
    string toGoatLatin(string sentence) {
        string res;
        string word;
        std::size_t wi{1};
        std::size_t sz = sentence.size();
        for (std::size_t i{0};i <= sz;++i) {
            if (i >= sz || sentence[i] == ' ') {
                if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u'
                || word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U') {
                    word += "ma";
                } else {
                    word = word.substr(1) + word[0] + "ma";
                }
                for (std::size_t j{0};j < wi;++j) {
                    word += 'a';
                }
                res += word;
                if (i < sz) {
                    res += ' ';
                }
                word = "";
                wi += 1;
            } else {
                word += sentence[i];
            }
        }
        return res;
    }
};