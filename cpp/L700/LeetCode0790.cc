#include <vector>

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};

    std::vector<std::vector<unsigned long long int>> matrixMulti(const std::vector<std::vector<unsigned long long int>> &mat1,  
                                                                 const std::vector<std::vector<unsigned long long int>> &mat2) {
        int R = mat1.size(), C = mat2.size(), T = mat2[0].size();
        std::vector<std::vector<unsigned long long int>> mat(R, std::vector<unsigned long long int>(T, 0));
        for (int i = 0;i < R;++i) {
            for (int k = 0;k < T;++k) {
                for (int j = 0;j < C;++j) {
                    mat[i][k] = (mat[i][k] + mat1[i][j] * mat2[j][k]) % MOD;
                }
            }
        }
        return mat;
    }

    std::vector<std::vector<unsigned long long int>> matrixPow(int n) {
        std::vector<std::vector<unsigned long long int>> mat{
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
        };
        std::vector<std::vector<unsigned long long int>> mat1{
            {0,0,0,1},
            {1,0,1,0},
            {1,1,0,0},
            {1,1,1,1}
        };
        while (n > 0) {
            if ((n & 1) == 1) {
                mat = matrixMulti(mat, mat1);
            }
            n = n >> 1;
            mat1 = matrixMulti(mat1, mat1);
        }
        return mat;
    }
public:
    int numTilings(int n) {
        std::vector<std::vector<unsigned long long int>> res = matrixPow(n);
        return static_cast<int>(res[3][3]);
    }

    int numTilingsDynamic(int n) {
        std::vector<std::vector<unsigned long long int>> dp(n + 1, std::vector(4, 0ULL));
        dp[0][3] = 1ULL;
        for (int i = 1;i <= n;++i) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
            dp[i][2] = (dp[i - 1][2] + dp[i - 1][0]) % MOD;
            for (int j = 0;j < 4;++j) {
                dp[i][3] = (dp[i][3] + dp[i - 1][j]) % MOD;
            }
        }
        return (int)dp[n][3];
    }
};