#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        std::unordered_map<int, int> pd;
        int N =  difficulty.size();
        if (N == 0) {
            return 0;
        }
        for (int i = 0;i < N;++i) {
            if (pd.find(profit[i]) == pd.end()) {
                pd[profit[i]] = difficulty[i];
            } else if (difficulty[i] < pd[profit[i]]) {
                pd[profit[i]] = difficulty[i];
            }
        }
        vector<std::pair<int, int>> profitDiff(pd.begin(), pd.end());
        std::sort(profitDiff.begin(), profitDiff.end(),  [](auto const &a, auto const &b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        int p = -1; // 大困難度的可以取之前的最大值
        for (std::pair<int, int> &cp : profitDiff) {
            cp.first = std::max(p, cp.first);
            p = cp.first;
        }
        int ans{0};
        for (int ablity : worker) {
            int low{0}, high = profitDiff.size();
            while (low < high) {
                int mid{(low + high) / 2};
                if (profitDiff[mid].second > ablity) {
                    high = mid;
                } else {
                    low  =  mid + 1;
                }
            }
            if (low > 0) {
                ans += profitDiff[low - 1].first;
            }
        }
        return ans;
    }
};