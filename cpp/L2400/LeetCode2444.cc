#include <vector>
using std::vector;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int N = nums.size();
        int left = -1, minI = -1, maxI = -1;
        long long int res{0};
        for (int i = 0;i < N;++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                minI = -1;
                maxI = -1;
                left = i;
                continue;
            }
            if (nums[i] == minK) {
                minI = i;
            }
            if (nums[i] == maxK) {
                maxI = i;
            }
            if (minI != -1 && maxI != -1) {
                res += std::min(minI, maxI) - left;
            }
        }
        return res;
    }
};

int main() {
    vector<int> r{4,3};
    Solution s;
    s.countSubarrays(r, 3, 3);
}