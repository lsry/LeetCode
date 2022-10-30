#include <string>
using std::string;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        std::size_t w1z{word1.size()}, w2z{word2.size()};
        std::size_t w1{0}, w2{0};
        bool flag{true};
        while (w1 < w1z || w2 < w2z) {
            if (w1 >= w1z) {
                res.push_back(word2[w2]);
                ++w2;
            } else if (w2 >= w2z) {
                res.push_back(word1[w1]);
                ++w1;
            } else if (flag) {
                res.push_back(word1[w1]);
                ++w1;
                flag = false;
            } else {
                res.push_back(word2[w2]);
                ++w2;
                flag = true;
            }
        }
        return res;
    }
};