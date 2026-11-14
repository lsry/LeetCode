#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
    constexpr static long long int MOD{1'000'000'007};

    long long int getA(long long int ab, long long int b, int k) {
        if (b == 0) {
            return ab;
        }
        long long int pow10 = modPow(10, k);
        long long int inv = modPow(pow10, MOD - 2);
        long long int diff = (ab - b + MOD) % MOD;
        return diff * inv % MOD;
    }

    long long int modPow(long long int a, long long int b) {
        long long int res{1};
        while (b > 0) {
            if ((b & 1) == 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b = b >> 1;
        }
        return res;
    }
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int N = s.size();
        vector<long long int> suffixNum(N + 1, 0), suffixSum(N + 1, 0), suffixCount(N + 1, 0);
        for (int i = 1;i <= N;++i) {
            suffixSum[i] = suffixSum[i - 1] + (s[i - 1] - '0');
        }
        long long int multiable{1};
        for (int i = N - 1;i >= 0;--i) {
            if (s[i] == '0') {
                suffixNum[i] = suffixNum[i + 1];
                suffixCount[i] = suffixCount[i + 1];
            } else {
                int num = s[i] - '0';
                suffixNum[i] = (num * multiable % MOD + suffixNum[i + 1]) % MOD;
                multiable = (multiable * 10) % MOD;
                suffixCount[i] = suffixCount[i + 1] + 1;
            }
        }
        int QN = queries.size();
        vector<int> ans(QN, 0);
        for (int i = 0;i < QN;++i) {
            int low = queries[i][0], high = queries[i][1];
            long long int sum = (suffixSum[high + 1] - suffixSum[low] + MOD) % MOD;
            long long int num = getA(suffixNum[low], suffixNum[high + 1], suffixCount[high + 1]);
            ans[i] = (sum * num) % MOD;
        }
        return ans;
    }
};

int main() {
    Solution s;
    string s1 = "58578833985";
    vector<vector<int>> querys{{0,0}};
    s.sumAndMultiply(s1, querys);
}
