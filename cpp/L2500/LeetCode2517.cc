#include <vector>
using std::vector;
#include <algorithm>

class Solution {
    bool check(vector<int> const &price, int k, int taste) {
        int ans{1}, cur{price[0]};
        for (std::size_t i{1};i < price.size();++i) {
            if (price[i] - cur >= taste) {
                ++ans;
                cur = price[i];
            }
        }
        return ans >= k;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        std::sort(price.begin(), price.end());
        int low{0}, high{price[price.size() - 1] - price[0] + 1};
        while (low < high) {
            int mid{low + (high - low) / 2};
            if (check(price, k, mid)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low - 1;
    }
};