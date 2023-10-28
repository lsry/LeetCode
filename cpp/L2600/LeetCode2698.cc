#include <string>
#include <string_view>

class Solution {
    bool check(std::string_view square, int num, int sum, int id) {
        if (id >= square.size()) {
            return num == sum;
        }
        for (int i = id, cur{0};i < square.size();++i) {
            cur = (square[i] - '0') + cur * 10;
            if (check(square, num, cur + sum, i + 1)) {
                return true;
            }
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int ans{1};
        for (int i = 9;i <= n;++i) {
            if (check(std::to_string(i * i), i, 0, 0)) {
                ans += i * i;
            }
        }
        return ans;
    }
};