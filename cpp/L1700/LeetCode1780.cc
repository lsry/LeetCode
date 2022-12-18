#include <array>

class Solution {
    constexpr static std::array<int, 15> pow3{{1, 3, 9, 27, 81, 243, 729, 2187, 6561, 
                        19683, 59049, 177147, 531447, 1594323, 4782969}};

    // 4ms
    bool trace(int n, int id) {
        if (n == 0) {
            return true;
        }
        if (id < 0) {
            return false;
        }
        for (int i = id;i >= 0;--i) {
            if (pow3[i] <= n && trace(n - pow3[i], i - 1)) {
                return true;
            }
        }
        return false;
    }   

    // 196ms
    bool enumBinary(int n) {
        int limit = 1 << 15;
        for (int x = 1;x < limit;++x) {
            int sum = 0;
            for (int t = x, j = 0;j < 15 && t != 0;++j, t = t >> 1) {
                if ((t & 1) == 1) {
                    sum += pow3[j];
                }
            }
            if (sum == n) {
                return true;
            }
        }
        return false;
    }                
public:
    bool checkPowersOfThree(int n) {
        
    }
};