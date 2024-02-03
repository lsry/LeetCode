class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        unsigned long long low{0ULL}, high{130000ULL};
        while (low < high) {
            unsigned long long mid{low + (high - low) / 2};
            unsigned long long count{mid * (mid + 1ULL) * (mid * 2ULL + 1ULL) * 2ULL};
            if (count < neededApples) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return 8 * high;
    }
};