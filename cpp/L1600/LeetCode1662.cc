#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        std::size_t wz1{word1.size()}, wz2{word2.size()};
        for (std::size_t wi{0}, wj{0}, ni{0}, nj{0};wi < wz1 || wj < wz2;) {
            if (wi >= wz1 || wj >= wz2) {
                return false;
            }
            std::size_t sz1{word1[wi].size()}, sz2{word2[wj].size()};
            while (ni < sz1 && nj < sz2) {
                if (word1[wi][ni] != word2[wj][nj]) {
                    return false;
                }
                ++nj;
                ++ni;
            }
            if (ni >= sz1) {
                ni = 0;
                wi ++;
            }
            if (nj >= sz2) {
                nj = 0;
                wj ++;
            }
            
        }
        return true;
    }
};