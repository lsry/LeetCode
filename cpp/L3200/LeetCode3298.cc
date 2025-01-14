#include <array>
#include <string>
using std::string;

class Solution {
    bool checkArray(std::array<int, 26> const &w1, std::array<int, 26> const &w2) {
        for (int i = 0;i < 26;++i) {
            if (w1[i] < w2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    long long validSubstringCount(string word1, string word2) {
        std::array<int, 26> w1{0}, w2{0};
        for (char c : word2) {
            w2[c - 'a'] += 1;
        }
        long long int ans{0LL};
        int w1z = word1.size();
        for (int low = 0, j = 0;j < w1z;++j) {
            w1[word1[j] - 'a'] += 1;
            if (!checkArray(w1, w2)) {
                continue;
            }
            int i{low};
            while (i <= j && checkArray(w1, w2)) {
                w1[word1[i] - 'a'] -= 1;
                ++i;
            }
            int leftCount = i - low;
            int rightCount = w1z - j;
            ans += 1LL * leftCount * rightCount;
            low = i;
        }
        return ans;
    }
};