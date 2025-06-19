#include <algorithm>
#include <array>
#include <limits>
#include <string>
using std::string;

class Solution {
public:
    int maxDifference(string s) {
        std::array<int, 26> counts{0};
        for (char c : s) {
            counts[c - 'a'] ++;
        }
        int maxOdd{0};
        int minEven{std::numeric_limits<int>::max()};
        for (int count : counts) {
            if (count > 0) {
                if (count % 2 == 0) {
                    minEven = std::min(minEven, count);
                } else {
                    maxOdd = std::max(maxOdd, count);
                }
            }
        }
        return maxOdd - minEven;
    }
};