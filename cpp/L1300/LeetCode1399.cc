#include <unordered_map>

class Solution {
public:
    int countLargestGroup(int n) {
        std::unordered_map<int, int> mp;
        for (int i = 1;i <= n;++i) {
            int sum{0};
            for (int x = i;x != 0;x /= 10) {
                sum += x % 10;
            }
            mp[sum] += 1;
        }       
        int num{0}, count{0};
        for (auto const &[sum, c] : mp) {
            if (c > num) {
                count = 1;
                num = c;
            } else if (c == num) {
                ++count;
            }
        }     
        return count;
    }
};                                                                       