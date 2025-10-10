#include <vector>
using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans{0};
        for (int left = 0, right = height.size() - 1;left < right;) {
            ans = std::max(ans, std::min(height[left], height[right]) * (right - left));
            if (height[left] <= height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
};