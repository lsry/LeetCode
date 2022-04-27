#include <vector>
using std::vector;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        for (int i = 0, j = 1;i < n;++i) {
            res[i] = j;
            if (j * 10 <= n) {
                j *= 10;
            } else {
                while (j % 10 == 9 || j + 1 > n) {
                    j /= 10;
                }
                j += 1;
            }
        }
        return res;
    }
};