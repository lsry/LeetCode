#include <string>
using std::string;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge;
        std::size_t w1{0}, w1z{word1.size()};
        std::size_t w2{0}, w2z{word2.size()};
        while (w1 < w1z || w2 < w2z) {
            if (w1 == w1z) {
                merge.push_back(word2[w2]);
                ++w2;
            } else if (w2 == w2z) {
                merge.push_back(word1[w1]);
                ++w1;
            } else if (word1[w1] > word2[w2]) {
                merge.push_back(word1[w1]);
                ++w1;
            } else if (word1[w1] < word2[w2]) {
                merge.push_back(word2[w2]);
                ++w2;
            } else {
                std::size_t w11{w1}, w22{w2};
                while (w11 < w1z && w22 < w2z && word1[w11] == word2[w22]) {
                    ++w11;
                    ++w22;
                }
                if (w11 == w1z) {
                    merge.push_back(word2[w2]);
                    ++w2;
                } else if (w22 == w2z) {
                    merge.push_back(word1[w1]);
                    ++w1;
                } else if (word1[w11] > word2[w22]) {
                    merge.push_back(word1[w1]);
                    ++w1;
                } else {
                    merge.push_back(word2[w2]);
                    ++w2;
                }
            }
        }
        return merge;
    }
};