#include <vector>
using std::vector;
#include <string>
using std::string;
#include <array>

class Solution {
    void addStrBit(string const &word, std::array<int, 26> &arr) {
        for (char c : word) {
            arr[c - 'a'] += 1;
        }
    }

    bool check(std::array<int, 26> &large, std::array<int, 26> &small) {
        for (int i = 0;i < 26;++i) {
            if (large[i] < small[i]) {
                return false;
            }
        }
        return true;
    }
    
    int getScore(vector<int> &scores, std::array<int, 26> &arr) {
        int ans{0};
        for (int i = 0;i < 26;++i) {
            ans += scores[i] * arr[i];
        }
        return ans;
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int N = words.size();
        int MASK = 1 << N;
        std::array<int, 26> arr{{0}};
        for (char c : letters) {
            arr[c - 'a'] += 1;
        }
        std::array<int, 26> wordArr{{0}};
        int max_score{0};
        for (int i = 1;i < MASK;++i) {
            std::fill(wordArr.begin(), wordArr.end(), 0);
            for (int j = 0;j < N;++j) {
                if (((i >> j) & 1) == 1) {
                    addStrBit(words[j], wordArr);
                }
            }
            if (check(arr, wordArr)) {
                max_score = std::max(max_score, getScore(score, wordArr));
            }
        }
        return max_score;
    }
};