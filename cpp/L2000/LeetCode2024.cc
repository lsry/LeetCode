#include <iostream>

#include <string>
using std::string;

class Solution {
public:
    /**
     * 双指针，以 T，F分类计算
     * 假设一段字符串目标全是 c，在源串中不同字符数目应小于等于 k，
     * 当大于 k 时，则可以移动左指针使不同字符数目小于等于 k
     */
    int maxConsecutiveAnswers(string answerKey, int k) {
        return std::max(getCnt(answerKey, 'T', k), getCnt(answerKey, 'F', k));
    }

    int getCnt(string &answers, char c, int k) {
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
