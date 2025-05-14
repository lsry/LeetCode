#include <cstddef>
#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007ULL};
    constexpr static std::size_t N{26z};

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
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<unsigned long long int>> unit(N, vector<unsigned long long int>(N, 0ULL));
        for (int i = 0;i < N;++i) {
            unit[i][i] = 1;
        }
        vector<vector<unsigned long long int>> mat(N, vector<unsigned long long int>(N, 0ULL));
        for (int i = 0;i < N;++i) {
            for (int j = 0;j < N;++j) {
                if ((j < i && j + nums[j] >= i) || (j > i && j + nums[j] - 26 >= i)) {
                    mat[i][j] = 1;
                }
            }
        }
        while (t > 0) {
            if ((t & 1) == 1) {
                unit = matrixMulti(unit, mat);
            }
            t /= 2;
            mat = matrixMulti(mat, mat);
        }
        vector<vector<unsigned long long int>> counts(N, vector<unsigned long long int>(1, 0ULL));
        for (char c : s) {
            counts[c - 'a'][0] += 1;
        }
        vector<vector<unsigned long long int>> resMat = matrixMulti(unit, counts);
        unsigned long long int ans{0ULL};
        for (int i = 0;i < N;++i) {
            ans = (ans + resMat[i][0]) % MOD;
        }
        return static_cast<int>(ans);
    }
};

int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2};
    s.lengthAfterTransformations("abcyy", 2, nums);
}