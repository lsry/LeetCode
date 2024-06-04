#include <vector>
using std::vector;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        int N = nums.size();
        for (int i = 0;i < N;++i) {
            // 儅被刪除元素數目小於最大可刪除元素數目
            while (!st.empty() && st.back() > nums[i] && i - st.size() < N - k) {
                st.pop_back();
            }
            st.push_back(nums[i]);
        }
        return vector<int>(st.begin(), st.begin() + k);
    }
};