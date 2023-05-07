#include <vector>
using std::vector;
#include <array>

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        std::array<unsigned long long int, 60> counts{{0}};
        for (int t : time) {
            counts[t % 60] += 1;
        }
        unsigned long long int num{0ULL};
        if (counts[0] > 1) {
            num += (counts[0] - 1) * counts[0] / 2;
        }
        if (counts[30] > 1) {
            num += (counts[30] - 1) * counts[30] / 2;
        }
        for (int i = 1;i < 30;++i) {
            num += counts[i] * counts[60 - i];
        }
        return static_cast<int>(num);
    }
};