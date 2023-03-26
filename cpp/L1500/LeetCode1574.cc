#include <vector>
using std::vector;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int az = arr.size();
        if (az < 2) {
            return 0;
        }
        int low = 0, high = az;
        for (;low + 1 < az && arr[low + 1] >= arr[low];++low);
        for (;high - 1 > low && arr[high - 1] >= arr[low];--high) {
            if (high < az && arr[high] < arr[high - 1]) {
                break;
            }
        }
        if (high == low + 1) {
            return 0;
        }
        int ans{std::min(high, az - (low + 1))};
        ans = std::min(ans, high - low - 1);
        for (low = low - 1;low >= -1;--low) {
            int t = low >= 0 ? arr[low] : -1;
            for (;high - 1 > low && arr[high - 1] >= t;--high) {
                if (high < az && arr[high] < arr[high - 1]) {
                    break;
                }
            }
            ans = std::min(ans, high - low - 1);
        }
        return ans;
    }
};