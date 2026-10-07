#include <vector>
using std::vector;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int N = arr.size();
        int ans{N + 1};
        vector<int> suffix(N, -1);
        for (int sum{0}, left{N - 1}, right{N - 1};left >= 0;--left) {
            sum += arr[left];
            while (right >= left && sum > target) {
                sum -= arr[right];
                --right;
            }
            int l = right - left + 1;
            if (sum == target && l > 0 && l < ans) {
                ans = l;
            }
            if (ans != N + 1) {
                suffix[left] = ans;
            }
        }
        ans = N + 1;
        for (int sum{0}, i = 0, j = 0;j < N;++j) {
            sum += arr[j];
            while (i <= j && sum > target) {
                sum -= arr[i];
                ++i;
            }
            if (sum == target && j - i + 1 > 0 && j + 1 < N) {
                int f1 = j - i + 1;
                int f2 = suffix[j + 1];
                if (f2 != -1) {
                    ans = std::min(ans, f1 + f2);
                }
            }
        }
        return ans == N + 1 ? -1 : ans;
    }
};
