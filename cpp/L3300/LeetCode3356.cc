#include <vector>
using std::vector;

class Solution {
    bool check(vector<int> const &nums, vector<vector<int>> const &queries, int limit) {
        int N = nums.size();
        vector<int> diff(N + 1, 0);
        for (int i = 0;i <= limit;++i) {
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1] + 1] -= queries[i][2];
        }
        for (int sum{0}, i{0};i < N;++i) {
            sum += diff[i];
            if (sum < nums[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        bool allZero{true};
        for (int num : nums) {
            if (num > 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) {
            return 0;
        }
        int low = 0, high = queries.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (check(nums, queries, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high == queries.size() ? -1 : high + 1;
    }
};

int main() {
    vector<int> a{5};
    vector<vector<int>> q{{0,0,5},{0,0,1},{0,0,3},{0,0,2}};
    Solution s;
    s.minZeroArray(a, q);
}