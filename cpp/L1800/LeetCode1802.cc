class Solution {
    bool check(int num, int index, int maxSum, int n) {
        unsigned long long int sum = 0ULL;
        if (num >= index + 1) {
            sum += static_cast<unsigned long long int>(num - index + num) * (index + 1) / 2;
        } else {
            sum += static_cast<unsigned long long int>(1 + num) * num / 2 + (index + 1 - num);
        }
        int left = n - 1 - index;
        if (num - 1 >= left) {
            sum += static_cast<unsigned long long int>(num - left + num - 1) * left / 2;
        } else {
            sum += static_cast<unsigned long long int>(1 + num - 1) * (num - 1) / 2 + (left - (num - 1));
        }
        return sum <= maxSum;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum + 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (!check(mid, index, maxSum, n)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low - 1;
    }
};