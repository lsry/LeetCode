#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
    unsigned long long int count(vector<int> const &arr, int index, std::unordered_map<int, int> &nums, std::unordered_map<int, unsigned long long int> &dp) {
        if (dp.find(arr[index]) != dp.end()) {
            return dp[arr[index]];
        }
        unsigned long long int res{1ULL};
        for (int i{0};static_cast<unsigned long long int>(arr[i]) * arr[i] <= static_cast<unsigned long long int>(arr[index]);++i) {
            if (arr[index] % arr[i] == 0 && nums.find(arr[i]) != nums.end() && nums.find(arr[index] / arr[i]) != nums.end()) {
                unsigned long long int left = count(arr, i, nums, dp);
                unsigned long long int right = count(arr, nums[arr[index] / arr[i]], nums, dp);
                unsigned long long int total = left * right % MOD;
                if (arr[i] * arr[i] != arr[index]) {
                    total = total * 2 % MOD;
                }
                res = (res + total) % MOD;
            }
        }
        dp[arr[index]] = res;
        return res;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        std::stable_sort(arr.begin(), arr.end());
        std::unordered_map<int, unsigned long long int> dp;
        std::unordered_map<int, int> nums;
        for (int i = 0;i < arr.size();++i) {
            nums[arr[i]] = i;
        }
        unsigned long long int res{0ULL};
        for (int i{0};i < arr.size();++i) {
            res = (res + count(arr, i, nums, dp)) % MOD;
        }
        return static_cast<int>(res);
    }
};