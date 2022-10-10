#include <vector>

class Solution {
public:
    int getKthMagicNumber(int k) {
        std::vector<int> res;
        res.push_back(1);
        int p3 = 0, p5 = 0, p7 = 0;
        for (int i = 1;i < k;++i) {
            int num = std::min(res[p3] * 3, std::min(res[p5] * 5, res[p7] * 7));
            if (num == res[p3] * 3) {
                ++p3;
            }
            if (num == res[p5] * 5) {
                ++p5;
            }
            if (num == res[p7] * 7) {
                ++p7;
            }
            res.push_back(num);
        }
        return res[k - 1];
    }
};