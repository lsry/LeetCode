#include <iostream>

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return std::max(getCnt(answerKey, 'T', k), getCnt(answerKey, 'F', k));
    }

    int getCnt(string & answers, char c, int k) {
        int sz = answers.size();
        int max = 0;
        int diff = 0;
        int len = 0;
        for (int li = 0, ri = 0;ri < sz;++ri) {
            if (answers[ri] == c) {
                ++diff;
            } 
            while (diff > k) {
                if (answers[li] == c) {
                    --diff;
                }
                ++li;
            }
            max = std::max(max, ri - li + 1);
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int max = s.maxConsecutiveAnswers("TTFTTFTT", 1);
    std::cout << max << std::endl;
    return 0;
}
