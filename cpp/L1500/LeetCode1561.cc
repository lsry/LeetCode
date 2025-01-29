#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        std::sort(piles.begin(), piles.end());
        int ans{0};
        for (int i = 0, j = piles.size() - 1;i < j - 1;++i, j -= 2) {
            ans += piles[j - 1];
        }      
        return ans;
    }
};