#include <stack>
#include <string>
using std::string;

class Solution {
public:
    /**
     * @brief 括號匹配必須滿足棧結構，因此當某一個半括號無法找到對應的即可記錄次數。同時由於棧只存放左括號，
     *        可省略掉棧，使用一個變量記錄遇到的左括號次數即可。
     */
    int minAddToMakeValid(string s) {
        int count = 0;
        int left{0};
        for (char const c : s) {
            if (c == '(') {
                ++left;
            } else if (c == ')') {
                if (left > 0) {
                    --left;
                } else {
                    ++count;
                }
            }
        }
        return left + count;
    }
};