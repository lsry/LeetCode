#include <algorithm>
#include <array>
#include <unordered_set>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
    const std::array<char, 10> digits{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string dec2bin(int num, int n) {
        string s;
        while (num > 0) {
            s.push_back(digits[num % 2]);
            num /= 2;
        }
        std::reverse(s.begin(), s.end());
        return s.size() < n ? string(n - s.size(), '0') + s : s;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        std::unordered_set<string> st(nums.begin(), nums.end());
        int N = nums.size();
        for (int i = 0;i < (1 << N);++i) {
            string s = dec2bin(i, N);
            if (!st.contains(s)) {
                return s;
            }
        }
        return "";
    }
};
