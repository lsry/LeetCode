#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        if (boxes.empty()) {
            return {};
        }
        std::size_t bz{boxes.size()};
        vector<int> res(bz, 0);
        int balls{0};
        for (std::size_t i{0};i < bz;++i) {
            if (boxes[i] == '1') {
                ++balls;
                res[0] += static_cast<int>(i - 0);
            }
        }
        int leftBalls{boxes[0] == '1' ? 1 : 0};
        for (std::size_t i{1};i < bz;++i) {
            res[i] = res[i - 1] + leftBalls - (balls - leftBalls);
            if (boxes[i] == '1') {
                ++leftBalls;
            }
        }
        return res;
    }
};