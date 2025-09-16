#include <vector>
using std::vector;

class Solution {
    bool haveZero(int n) {
        while (n > 0) {
            if (n % 10 == 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1;i <= n / 2;++i) {
            if (haveZero(i) && haveZero(n - i)) {
                return {i, n - i};
            }
        }
        return {};
    }
};