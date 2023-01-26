#include <vector>
using std::vector;
#include <unordered_map>
#include <functional>

class Solution {
    int kWidth{5};
    int kMask{0b11111};
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> cnt(batchSize, 0);
        for (int g : groups) {
            cnt[g % batchSize] += 1;
        }
        std::unordered_map<long long int, int> memo;
        std::function<int(long long int)> dfs{[&](long long int mask) -> int {
            if (mask == 0LL) {
                return 0;
            }
            auto it{memo.find(mask)};
            if (it != memo.end()) {
                return it->second;
            }
            int total{0};
            for (int i = 1;i < batchSize;++i) {
                int amount{static_cast<int>((mask >> ((i - 1) * kWidth)) & kMask)};
                total += amount * i;
            }
            int best{0};
            for (int i = 1;i < batchSize;++i) {
                int amount{static_cast<int>((mask >> ((i - 1) * kWidth)) & kMask)};
                if (amount > 0) {
                    int res{dfs(mask - (1LL << ((i - 1) * kWidth)))};
                    if ((total - i) % batchSize == 0) {
                        ++res;
                    }
                    best = std::max(best, res);
                }
            }
            memo[mask] = best;
            return best;
        }};
        long long int start{0LL};
        for (int i{batchSize - 1};i > 0;--i) {
            start = (start << kWidth) | cnt[i];
        }
        return dfs(start) + cnt[0];
    }
};