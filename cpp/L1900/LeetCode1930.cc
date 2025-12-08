#include <string>
#include <unordered_set>
#include <vector>
using std::string;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        std::unordered_set<int> st;
        int N = s.size();
        std::vector<int> rightChars(N, 0);
        for (int i = N - 2;i >= 0;--i) {
            rightChars[i] = rightChars[i + 1] | (1 << (s[i + 1] - 'a'));
        }
        for (int leftChar{0}, i{1};i < N - 1;++i) {
            leftChar = leftChar | (1 << (s[i - 1] - 'a'));
            for (int j = 0;j < 26;++j) {
                if (((leftChar >> j) & 1) == 1 &&
                    ((rightChars[i] >> j) & 1) == 1) {
                    st.insert(j * 26 + (s[i] - 'a'));
                }
            }
        }
        return st.size();
    }
};
