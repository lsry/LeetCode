#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        vector<int> neg;
        long long int posProd{1};
        long long int ans{nums[0]};
        for (int num : nums) {
            if (num > 0) {
                posProd *= num;
            } else if (num < 0) {
                neg.push_back(num);
            }
            ans = std::max(ans, static_cast<long long int>(num));
        }
        if (ans <= 0 && neg.size() < 2) {
            return ans;
        }
        int NN = neg.size();
        std::sort(neg.begin(), neg.end());
        for (int i = 0;i < NN;i += 2) {
            if (i < NN && i + 1 < NN) {
                posProd = posProd * neg[i] * neg[i + 1];
            }
        }
        return posProd;
    }
};