#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        std::unordered_map<int, std::pair<int, int>> map;
        for (int num : nums) {
            int digit{0};
            int x{num};
            while (x != 0) {
                digit += x % 10;
                x /= 10;
            }
            std::pair<int, int> &pair{map[digit]};
            if (num > pair.first) {
                std::swap(num, pair.first);
            }
            if (num > pair.second) {
                std::swap(num, pair.second);
            }
        }
        int ans{-1};
        for (auto const &[a, b] : map) {
            if (b.first > 0 && b.second > 0) {
                ans = std::max(ans, b.first + b.second);
            }
        }
        return ans;
    }
};