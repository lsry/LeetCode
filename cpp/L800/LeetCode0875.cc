#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = piles[0];
        for (int p : piles) {
            if (p > max) {
                max = p;
            }
        }
        int low = 1, high = max;
        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            for (int p : piles) {
                if (p <= mid) {
                    count += 1;
                } else if (p % mid == 0) {
                    count += p / mid;
                } else {
                    count += p / mid + 1;
                }
            }
            if (count > h) { // 不满足条件的加 1
                low = mid + 1;
            } else {
                high = mid; // 满足条件的不变
            }
        }
        return high;
    }
};