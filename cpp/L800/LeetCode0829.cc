class Solution {
public:
    int consecutiveNumbersSumDoublePointer(int n) {
        int ans = 0;
        int sum = 0;
        for (int i = 1, j = 1;i <= j && j <= n;++j) {
            sum += j;
            if (sum < n) {
                continue;
            }
            while (i <= j && sum > n) {
                sum -= i;
                ++i;
            }
            if (sum == n) {
                ++ans;
            }
        }
        return ans;
    }

    int consecutiveNumbersSum(int n) {
        int ans = 0;
        int n2 = 2 * n;
        for (int k = 1;k * k < n2;++k) {
            if (n2 % k != 0) {
                continue;
            }
            if ((n2 / k + 1 - k) % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};