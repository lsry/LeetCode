#include<vector>
using std::vector;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        ans.reserve(20);
        for (unsigned long long int f = 10, e = 99, len = 2;f <= high;f = f * 10, e = e * 10 + 9, ++len) {
            if (e < low) {
                continue;
            }
            for (int j = 1;j <= 10 - len;++j) {
                int num = 0;
                for (int l = 0, k = j;l < len;++l, ++k) {
                    num = num * 10 + k;
                }
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
                if (num > high) {
                    break;
                }
            }
        }
        return ans;
    }
};
