#include <queue>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto f{[](std::pair<unsigned long long int, int> const &p1, std::pair<unsigned long long int, int> const &p2) {
            return p1.first == p2.first ? p1.second > p2.second : p1.first > p2.first;
        }};
        std::priority_queue<std::pair<unsigned long long int, int>, vector<std::pair<unsigned long long int, int>>, decltype(f)> pq;
        for (int i = 0;i < nums.size();++i) {
            pq.push(std::pair<unsigned long long int, int>(nums[i], i));
        }
        for (int i = 0;i < k;++i) {
            auto [num, idx] = pq.top();
            pq.pop();
            num = (num * multiplier) % MOD;
            pq.push(std::pair<unsigned long long int, int>(num, idx));
        }
        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();
            nums[idx] = num;
        }
        return nums;
    }
};