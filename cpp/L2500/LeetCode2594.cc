#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
using std::vector;

class Solution {
    bool check(vector<int> const &ranks, int cars, long long int time) {
        for (auto it{ranks.cbegin()};it != ranks.cend() && cars > 0;++it) {
            int n = static_cast<int>(std::sqrt(static_cast<double>(time) / *it));
            cars -= n;
        }   
        return cars <= 0;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        std::sort(ranks.begin(), ranks.end(), std::greater<int>());
        long long int low{0LL}, high{static_cast<long long int>(ranks[0]) * cars * cars};
        while (low < high) {
            long long int mid = low + (high - low) / 2;
            if (check(ranks, cars, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};