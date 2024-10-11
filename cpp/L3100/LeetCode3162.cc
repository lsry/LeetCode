#include <algorithm>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::unordered_map<int, int> st1;
        int maxN1 = 0;
        for (int num : nums1) {
            st1[num] += 1;
            maxN1 = std::max(maxN1, num);
        }
        int cnt{0};
        for (int num : nums2) {
            if (num == 0) {
                cnt += nums1.size();
            } else {
                for (int x = 1;x * num * k <= maxN1;++x) {
                    auto it = st1.find(x * num * k);
                    if (it != st1.end()) {
                        cnt += it->second;
                    }
                }
            }
        }
        return cnt;
    }
};