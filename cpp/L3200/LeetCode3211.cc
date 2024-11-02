#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        int N = 1 << n;
        for (int i = 0;i < N;++i) {
            string r;
            bool flag{true};
            for (int j = 0;j < n;++j) {
                int x = (i >> j) & 1;
                if (x == 1) {
                    r.push_back('1');
                } else if (r.empty() || r.back() != '0') {
                    r.push_back('0');
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(r);
            }
        }
        return res;
    }
};