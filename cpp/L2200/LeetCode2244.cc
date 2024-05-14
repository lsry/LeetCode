#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        if (tasks.empty()) {
            return 0;
        }
        std::unordered_map<int, int> counts;
        for (int task : tasks) {
            counts[task] += 1;
        }
        int ans{0};
        for (auto const &[hard, count] : counts) {
            int cur{-1};
            for (int y{count / 3};y >= 0;--y) {
                if ((count - 3 * y) % 2 == 0 && (count - y) % 2 == 0) {
                    cur = (count - y) / 2;
                    break;
                }
            }
            if (cur == -1) {
                return -1;
            }
            ans += cur;
        }
        return ans == 0 ? -1 : ans;
    }
};