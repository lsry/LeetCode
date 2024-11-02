#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num] += 1;
        }
        int ans{0};
        for (auto const &[k, v] : mp) {
            if (v == 2) {
                ans ^= k;
            }
        }
        return ans;
    }
};