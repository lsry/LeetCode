#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (auto it{nums.begin()};it < (nums.end() - 1);++it) {
            for (auto jt{it + 1};jt != nums.end();++jt) {
                int p{(*it) * (*jt)};
                map[p] += 1;
            }
        }
        int ans{0};
        for (auto const &[k, v] : map) {
            ans += 2 * v * (v - 1) * 2;
        }
        return ans;
    }
};