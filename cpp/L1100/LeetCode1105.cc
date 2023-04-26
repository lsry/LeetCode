#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        std::size_t bz{books.size()};
        vector<int> dp(bz + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i{1};i <= bz;++i) {
            int width{0};
            int height{0};
            for (int j = i;j >= 1 && width + books[j - 1][0] <= shelfWidth;--j) {
                height = std::max(books[j - 1][1], height);
                dp[i] = std::min(dp[i], dp[j - 1] + height);
                width += books[j - 1][0];
            }
        }
        return dp[bz];
    }
};