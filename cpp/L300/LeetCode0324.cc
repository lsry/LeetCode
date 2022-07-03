#include <vector>
using std::vector;

#include <algorithm>

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int nz = nums.size();
        if (nz < 2) {
            return;
        }
        std::stable_sort(nums.begin(), nums.end());
        int mi{(nz - 1)/ 2};
        std::vector<int> small;
        std::vector<int> large;
        for (int i{mi};i >= 0;--i) {
            small.push_back(nums[i]);
        }
        for (int i{nz - 1};i > mi;--i) {
            large.push_back(nums[i]);
        }
        std::size_t ni{0};
        for (int i{0},j{0};i <= mi;++i) {
            nums[ni] = small[i];
            ++ni;
            if (j < large.size()) {
                nums[ni] = large[j];
                ++j;
                ++ni;
            }
        }
    }
};