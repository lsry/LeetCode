#include <vector>
using std::vector;
#include <queue>
#include <limits>

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) {
            return 0;
        }
        int ans{nums[0]}, sum{0}, suffixSum{0};
        auto f{[](std::pair<int, int> const &p1, std::pair<int, int> const &p2) {
            return p1.first < p2.first;
        }};
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(f)> pq(f);
        for (int i{0};i < N;++i) {
            suffixSum += nums[N - 1 - i];
            pq.emplace(std::pair<int,int>(suffixSum, N - 1 - i));
            sum += nums[i];
            if (sum > ans) {
                ans = sum;
            }
            if (sum <= 0) {
                sum = 0;
            }
        }
        int preSum{0}, preSumMax{std::numeric_limits<int>::min()};
        for (int i{0};i < N;++i) {
            preSum += nums[i];
            preSumMax = std::max(preSum, preSumMax);
            while (!pq.empty() && pq.top().second <= i) {
                pq.pop();
            }
            ans = std::max(ans, preSumMax + (pq.empty() ? 0 : pq.top().first));
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> a{-3,-2,-1,-4,-5};
    s.maxSubarraySumCircular(a);
    return 0;
}
