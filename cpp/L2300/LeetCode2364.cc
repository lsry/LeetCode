#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        std::unordered_map<int, int> cntMap;
        long long int N = nums.size();
        long long int total = N * (N - 1) / 2LL;
        long long int equal = 0LL;
        for (int i = 0;i < N;++i) {
            int c = nums[i] - i;
            int cnt = cntMap[c];
            equal += cnt;
            cntMap[c] += 1;
        }
        return total - equal;
    }
};