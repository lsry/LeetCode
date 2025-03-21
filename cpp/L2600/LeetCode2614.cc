#include <vector>
using std::vector;

class Solution {
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2;i * i <= n;++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans{0};
        int N = nums.size();
        for (int i = 0, j = 0;i < N && j < N;++i, ++j) {
            if (isPrime(nums[i][j])) {
                ans = std::max(ans, nums[i][j]);
            }
        }
        for (int i = 0, j = N - 1;i < N && j >= 0;++i, --j) {
            if (isPrime(nums[i][j])) {
                ans = std::max(ans, nums[i][j]);
            }
        }
        return ans;
    }
};