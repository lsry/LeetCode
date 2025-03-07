#include <algorithm>
#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int N = nums.size();
        std::sort(nums.begin(), nums.end());
        int T = 1 << N;
        int ans{0};
        std::unordered_set<int> st;
        for (int t{1};t < T;++t) {
            bool insert{true};
            for (int i = 0;i < N;++i) {
                if (((t >> i) & 1) == 1) {
                    int x = nums[i];
                    if (st.contains(x - k)) {
                        insert = false;
                        break;
                    }
                    st.insert(x);
                }
            }
            if (insert) {
                ++ans;
            }
            st.clear();
        }
        return ans;
    }
};