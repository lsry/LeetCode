#include <string>
#include <map>
using std::string;
#include <vector>
using std::vector;
#include <iostream>

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        std::map<string, int> cnt;
        for (string const &word : words) {
            cnt[word]++;
        }
        int legth{0};
        bool singleExist{false};
        for (auto &[word, count] : cnt) {
            std::cout << word << ": " << count << std::endl;
            if (word[0] == word[1]) {
                if (count % 2 == 0) {
                    legth += count * 2;
                    count = 0;
                } else {
                    legth += (count - 1) * 2;
                    count = 1;
                    singleExist = true;
                }
            } else {
                string wordB;
                wordB.push_back(word[1]);
                wordB.push_back(word[0]);
                // 儅 cnt 為 unordered_map 時，用 cnt[] 重載會導致儅 wordB 不存在時插入元素，cnt 重新散列，發生迭代器失效，從而無法遍歷所有元素
                int countB = cnt[wordB]; 
                if (countB >= count) {
                    legth += 4 * count;
                    cnt[wordB] -= count;
                    count = 0;
                } else if (countB > 0) {
                    legth += 4 * countB;
                    count -= countB;
                    cnt[wordB] = 0;
                }
            }
        }
        if (singleExist) {
            legth += 2;
        }
        return legth;
    }
};

int main() {
    Solution s;
    vector<string> words{"oo","vv","uu","gg","pp","ff","ss","yy","vv","cc","rr","ig","jj","uu","ig","gb","zz","xx","ff","bb","ii","dd","ii","ee","mm","qq","ig","ww","ss","tt","vv","oo","ww","ss","bi","ff","gg","bi","jj","ee","gb","qq","bg","nn","vv","oo","bb","pp","ww","qq","mm","ee","tt","hh","ss","tt","ee","gi","ig","uu","ff","zz","ii","ff","ss","gi","yy","gb","mm","pp","uu","kk","jj","ee"};
    s.longestPalindrome(words);
}