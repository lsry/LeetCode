#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
    constexpr static unsigned long long int MOD{1'000'000'007};

public:
    int countTrapezoids(vector<vector<int>>& points) {
        std::unordered_map<int, int> yCount;
        for (vector<int> const &point : points) {
            yCount[point[1]]++;
        }
        std::unordered_map<int, unsigned long long int> mp;
        unsigned long long int before{0ULL}, ans{0ULL};
        for (auto const &[k, v] : yCount) {
            unsigned long long int x = 1ULL * v * (v - 1) / 2;
            ans = (ans + before * x) % MOD;
            before += x;
        }
        return static_cast<int>(ans);
    }
};
