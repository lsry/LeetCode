#include <vector>
using std::vector;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int fz = fruits.size();
        int low = -1;
        while (low + 1 < fz && fruits[low + 1][0] < startPos) {
            ++low;
        }
        int amount{0};
        int high = low + 1;
        while (high < fz && fruits[high][0] <= startPos + k) {
            amount += fruits[high][1];
            ++high;
        }
        int maxAmount{amount};
        for (int low_left{low}, high_left{high}, amount_left{amount};low_left >= 0 && startPos - fruits[low_left][0] <= k;--low_left) {
            amount_left += fruits[low_left][1];
            int right{std::max(startPos + k - 2 * (startPos - fruits[low_left][0]), startPos)};
            while (high_left - 1 > low_left && fruits[high_left - 1][0] > right) {
                amount_left -= fruits[high_left - 1][1];
                --high_left;
            }
            maxAmount = std::max(maxAmount, amount_left);
        }
        high = fz;
        while (high - 1 >= 0 && fruits[high - 1][0] > startPos) {
            --high;
        }
        amount = 0;
        low = high - 1;
        while (low >= 0 && startPos - fruits[low][0] <= k) {
            amount += fruits[low][1];
            --low;
        }
        maxAmount = std::max(maxAmount, amount);
        for (int low_right{low}, high_right{high}, amount_right{amount};high_right < fz && fruits[high_right][0] - startPos <= k;++high_right) {
            amount_right += fruits[high_right][1];
            int left{std::min(startPos, startPos - k + 2 * (fruits[high_right][0] - startPos))};
            while (low_right + 1 < high_right && fruits[low_right + 1][0] < left) {
                amount_right -= fruits[low_right + 1][1];
                ++low_right;
            }
            maxAmount = std::max(maxAmount, amount_right);
        }

        return maxAmount;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;  
    vector<vector<int>> v{{0,7},{7,4},{9,10},{12,6},{14,8},{16,5},{17,8},{19,4},{20,1},{21,3},{24,3},{25,3},{26,1},{28,10},{30,9},{31,6},{32,1},{37,5},{40,9}};
    s.maxTotalFruits(v, 21, 30);
    return 0;
}
