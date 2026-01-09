#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        std::sort(capacity.begin(), capacity.end(), std::greater<int>());
        int appleTotal = std::accumulate(apple.begin(), apple.end(), 0);
        int ans{0};
        for (int i = 0;i < capacity.size() && appleTotal > 0;++i) {
            appleTotal -= capacity[i];
            ++ans;
        }
        return ans;
    }
};
