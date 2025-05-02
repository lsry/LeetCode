#include <algorithm>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int ans{0LL};
        int N = nums.size();
        int maxValue{*std::max_element(nums.begin(), nums.end())};
        std::queue<int> q;
        for (int high{0};high < N;++high) {
            if (nums[high] == maxValue) {
                q.push(high);
            }
            while (q.size() > k) {
                q.pop();
            }
            if (q.size() == k) {
                int low = q.front();
                ans += low + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{1,3,2,3,3};
    s.countSubarrays(v, 2);
}