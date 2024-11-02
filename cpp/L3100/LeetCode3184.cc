#include <array>
#include <vector>
using std::vector;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        std::array<int, 24> mods{{0}};
        for (int hour : hours) {
            mods[hour % 24] += 1;
        }      
        int ans{0};
        for (int i = 1;i <= 11;++i) {
            ans += mods[i] * mods[24 - i];
        }
        ans += mods[0] * (mods[0] - 1) / 2;
        ans += mods[12] * (mods[12] - 1) / 2;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> d{11,24,6,19,13};
    s.countCompleteDayPairs(d);
}