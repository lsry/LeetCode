#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        std::unordered_map<int, int> counts;
        int beforeMax{0};
        int intervalValue{0};
        int N = prizePositions.size();
        for (int right{N - 1}, left{N - 1};left >= 0;--left) {
            intervalValue ++;
            while (prizePositions[right] - prizePositions[left] > k) {
                --intervalValue;
                --right;
            }
            beforeMax = std::max(beforeMax, intervalValue);
            counts[prizePositions[left]] = beforeMax;
        }
        intervalValue = 0;
        int ans{0};
        for (int left{0}, right{0};right < N;++right) {
            intervalValue++;
            while (right + 1 < N && prizePositions[right + 1] == prizePositions[right]) {
                ++intervalValue;
                ++right;
            }
            while (prizePositions[right] - prizePositions[left] > k) {
                --intervalValue;
                ++left;
            }
            int rightMax = right + 1 >= N ? 0 : counts[prizePositions[right + 1]];
            ans = std::max(ans, intervalValue + rightMax);
        }
        return ans;
    }
};