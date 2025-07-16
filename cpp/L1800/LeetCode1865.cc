#include <unordered_map>
#include <vector>
using std::vector;

class FindSumPairs {
    vector<int> nums2;
    std::unordered_map<int, int> counts1, counts2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2): nums2(nums2) {
        for (int num : nums1) {
            counts1[num]++;
        }
        for (int num : nums2) {
            counts2[num]++;
        }
    }
    
    void add(int index, int val) {
        int before = nums2[index];
        int after = before + val;
        nums2[index] = after;
        counts2[before]--;
        counts2[after]++;
    }
    
    int count(int tot) {
        int ans{0};
        for (auto const &[n, f] : counts1) {
            ans += f * counts2[tot - n];
        }
        return ans;
    }
};