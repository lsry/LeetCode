#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left;i <= right;++i) {
            string num = std::to_string(i);
            bool flag = true;
            for (const char &c : num) {
                if (c == '0') {
                    flag = false;
                    break;
                }
                int x = c - '0';
                if (i % x != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(i);
            }
        }
        return res;
    }
};