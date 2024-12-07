#include <cmath>
class Solution {
    bool checkPrime(int n) {
        if (n == 1) {
            return false;
        }
        if (n == 2 || n == 3 || n == 5) {
            return true;
        }
        int r = std::sqrt(n);
        for (int i = 2;i <= r;++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int nonSpecialCount(int l, int r) {
        int sl = static_cast<int>(std::sqrt(l));
        int sr = static_cast<int>(std::sqrt(r));
        int ans = r - l + 1;
        for (int i = sl;i <= sr;++i) {
            if (checkPrime(i) && i * i >= l && i * i <= r) {
                --ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.nonSpecialCount(1, 2);
}