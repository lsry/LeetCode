#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for (auto it{digits.rbegin()};it != digits.rend();++it) {
            int x = *it + carry;
            res.emplace_back(x % 10);
            carry = x / 10;
        }
        if (carry > 0) {
            res.emplace_back(carry);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
