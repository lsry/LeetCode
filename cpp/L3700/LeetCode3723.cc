#include <array>
#include <string>
using std::string;

class Solution {
    constexpr static std::array<char, 10> bits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
public:
    string maxSumOfSquares(int num, int sum) {
        string r;
        for (int i = 0;i < num;++i) {
            if (sum >= 9) {
                r.push_back('9');
                sum -= 9;
            } else if (sum > 0) {
                r.push_back(bits[sum]);
                sum = 0;
            } else {
                r.push_back('0');
            }
        }
        return sum == 0 ? r : "";
    }
};
