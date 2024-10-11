#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::unordered_map<int, int> st1, st2;
        int maxN1 = 0;
        for (int num : nums1) {
            st1[num] += 1;
            maxN1 = std::max(maxN1, num);
        }
        for (int num : nums2) {
            st2[num] += 1;
        }
        long long cnt{0};
        for (auto const &[num, count] : st2) {
            if (num == 0) {
                cnt += nums1.size() * count;
            } else {
                for (int x = 1;x * num * k <= maxN1;++x) {
                    auto it = st1.find(x * num * k);
                    if (it != st1.end()) {
                        cnt += it->second * 1LL * count;
                    }
                }
            }
        }
        return cnt;
    }
};