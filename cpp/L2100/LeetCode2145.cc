#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long int mv{std::numeric_limits<int>::max()}, mx{std::numeric_limits<int>::min()};
        long long int initial{0};
        for (int diff : differences) {
            initial += diff;
            mv = std::min(mv, initial);
            mx = std::max(mx, initial);
        }
        mv = lower - mv;
        mv = std::max(mv, static_cast<long long int>(lower));
        mx = upper - mx;
        mx = std::min(mx, static_cast<long long int>(upper));
        return mx >= mv ? mx - mv + 1 : 0;
    }
};