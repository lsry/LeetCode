#include <vector>
using std::vector;
#include <algorithm>

class Solution {
    constexpr static int MOD{1'000'000'007};
    void initialZero(vector<vector<int>> &arr) {
        for (vector<int> &ar : arr) {
            for (int &a : ar) {
                a = 0;
            }
        }
    }
    int sumVec(vector<vector<int>> &arr) {
        int ans{0};
        for (vector<int> &ar : arr) {
            for (int a : ar) {
                ans = (ans % MOD + a % MOD) % MOD;
            }
        }
        return ans;
    }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int allMax{*std::max_element(rollMax.begin(), rollMax.end())};
        vector<vector<int>> arrA(6, vector<int>(allMax, 0));
        vector<vector<int>> arrT(6, vector<int>(allMax, 0));
        for (int i = 0;i < 6;++i) {
            arrA[i][0] = 1;
        }
        vector<vector<int>> &dp{arrA};
        vector<vector<int>> &dt{arrT};
        for (int i = 2;i <= n;++i) {
            initialZero(dt);
            for (int i = 0;i < 6;++i) {
                for (int j = 0;j < 6;++j) {
                    if (j == i) {
                        continue;
                    }
                    for (int k = 0;k < rollMax[j];++k) {
                        dt[i][0] = (dt[i][0] % MOD + dp[j][k] % MOD) % MOD;
                    }
                }
                for (int j = 1;j < rollMax[i];++j) {
                    dt[i][j] = (dt[i][j] % MOD + dp[i][j - 1] % MOD);
                }
            }
            vector<vector<int>> &dc = dp;
            dp = dt;
            dt = dc;
        }   
        return sumVec(dp);
    }
};