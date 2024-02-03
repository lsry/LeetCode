#include <vector>
using std::vector;

class Solution {
    int computeMaxAlloys(vector<int> const &compose, vector<int> const &stocks, vector<int> const &cost, int budget, int n) {
        int low{0}, high{1'000'000'000};
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long money{0LL};
            for (int i = 0;i < n;++i) {
                long long mount = static_cast<long long>(compose[i]) * mid - stocks[i];
                if (mount <= 0) {
                    continue;
                }
                money += mount * cost[i];
            }
            if (money > budget) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low - 1;
    }
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans{0};
        for (vector<int> const &compose : composition) {
            int curMount = computeMaxAlloys(compose, stock, cost, budget, n);
            ans = std::max(ans, curMount);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> composes{{1,1,1},{1,1,10}};
    vector<int> stocks{0,0,0};
    vector<int> cost{1,2,3};
    s.maxNumberOfAlloys(3,2,15,composes, stocks, cost);
    return 0;
}
