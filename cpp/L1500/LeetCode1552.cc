#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        int PN = position.size();
        int low{1}, high{position[PN - 1]};
        int ans = 0;
        for (;low <= high;) {
            int mid = low + (high - low) / 2;
            int count{1}, lastId{0};
            for (int i = 1;i < PN;++i) {
                if (position[i] - position[lastId] >= mid) {
                    ++count;
                    lastId = i;
                }
            }
            if (count >= m) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};