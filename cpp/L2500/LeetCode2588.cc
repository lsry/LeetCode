#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        std::unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;
        int x = 0;
        long long ans{0};
        for (int num : nums) {
            x ^= num;
            ans += prefixMap[x];
            prefixMap[x] += 1;
        }
        return ans;
    }
};