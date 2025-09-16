#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            while (!ans.empty() && std::gcd(ans.back(), num) > 1) {
                int g = std::gcd(ans.back(), num);
                num = (ans.back() / g) * num;
                ans.pop_back();
            }
            ans.push_back(num);
        }      
        return ans;
    }
};