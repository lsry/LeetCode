#include <string>
using std::string;

class Solution {
    int maxSuffix(string const &word) {
        int left = 0, N = word.size();
        for (int j = 1;j < N;) {
            int k = 0;
            while (j + k < N && word[left + k] == word[j + k]) {
                ++k;
            }
            if (j + k < N && word[left + k] < word[j + k]) {
                int t = left;
                left = j;
                j = std::max(j + 1, t + k + 1);
            } else {
                j = j + k + 1;
            }
        }
        return left;
    }
public:
    string answerString(string word, int numFriends) {
        int N = word.size();
        if (numFriends == 1) {
            return word;
        }
        int left = maxSuffix(word);
        return word.substr(left, std::min(N - numFriends + 1, N - left));
    }
};