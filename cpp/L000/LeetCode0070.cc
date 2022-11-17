#include <array>

class Solution {
    std::array<std::array<unsigned long long int, 2>, 2> matrixPow(std::array<std::array<unsigned long long int, 2>, 2> &m, int n) {
        std::array<std::array<unsigned long long int, 2>, 2> E{{{1, 0}, {0, 1}}};
        while (n != 0) {
            if ((n & 1) == 1) {
                E = matrixMul(E, m);
            }
            n = n >> 1;
            m = matrixMul(m, m);
        }
        return E;
    }

    std::array<std::array<unsigned long long int, 2>, 2> matrixMul(std::array<std::array<unsigned long long int, 2>, 2> &m1, std::array<std::array<unsigned long long int, 2>, 2> &m2) {
        std::array<std::array<unsigned long long int, 2>, 2> r;
        for (int i = 0;i < 2;++i) {
            for (int j = 0;j < 2;++j) {
                r[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j];
            }
        }
        return r;
    }
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        std::array<std::array<unsigned long long int, 2>, 2> M{{{1, 1}, {1, 0}}};
        M = matrixPow(M, n);
        return M[0][0];
    }
};