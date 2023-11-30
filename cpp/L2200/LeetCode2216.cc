#include <array>
#include <utility>
#include <vector>
using std::vector;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }      
        std::array<std::pair<int, int>, 2> pr;
        pr[1].first = nums[0];
        pr[1].second = 1;
        for (std::size_t i{1};i < nums.size();++i) {
            int a = pr[0].second, b = pr[0].first;
            if (nums[i] != pr[1].first) {
                if (pr[1].second + 1 > pr[0].second) {
                    pr[0].second = pr[1].second + 1;
                    pr[0].first = nums[i];
                }
            }
            if (a + 1 > pr[1].second) {
                pr[1].first = nums[i];
                pr[1].second = a + 1;
            }
        }
        return nums.size() - pr[0].second;
    }
};

int main() {
    Solution s;
    vector<int> arr{1,1,2,2,3,3};
    s.minDeletion(arr);
}