#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = std::accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int CN = cardPoints.size();
        int N = CN - k;
        if (N <= 0) {
            return sum;
        }
        int other{0}, target{sum};
        for (int low = 0, high{0};high < CN;++high) {
            if (high - low + 1 <= N) {
                other += cardPoints[high];
                if (high - low + 1 == N) {
                    target = other;
                }
            } else {
                other = other - cardPoints[low] + cardPoints[high];
                target = std::min(target, other);
                ++low;
            }
        }
        return sum - target;
    }
};