#include <vector>
using std::vector;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int az = arr.size();
        int ans = 0;
        int mv = 0;
        for (int i = 0;i < az;++i) {
            mv = std::max(mv, arr[i]);
            if (i == mv) {
                ++ans;
            }
        }
        return ans;
    }
};