#include <algorithm>
#include <array>
#include <vector>
using std::vector;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        std::array<int, 101> mp{0};
        for (int num : nums) {
            mp[num]++;
        }
        int freq{0};
        for (int f : mp) {
            freq = std::max(freq, f);
        }
        int ans{0};
        for (int f : mp) {
            if (f == freq) {
                ans += freq;
            }
        }
        return ans;
    }
};