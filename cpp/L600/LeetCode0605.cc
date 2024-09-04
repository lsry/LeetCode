#include <vector>
using std::vector;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count{0};
        int fz = flowerbed.size();
        for (int i = 0;i < fz;++i) {
            if (flowerbed[i] == 1) {
                continue;
            }
            if ((i - 1 < 0 || flowerbed[i - 1] == 0) && (i + 1 >= fz || flowerbed[i + 1] == 0)) {
                ++count;
                flowerbed[i] = 1;
            }
        }
        return count >= n;
    } 
};