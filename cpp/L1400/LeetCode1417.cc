#include <string>
using std::string;
#include <vector>

class Solution {
public:
    string reformat(string s) {
        std::vector<char> alphs, nums;
        for (char const &c : s) {
            if (c >= '0' && c <= '9') {
                nums.push_back(c);
            } else {
                alphs.push_back(c);
            }
        }
        std::size_t az{alphs.size()}, nz{nums.size()};
        if (!(az == nz || az == nz + 1 || nz == az + 1)) {
            return "";
        }
        string res;
        std::vector<char> &a = alphs, &n = nums;
        if (a.size() < n.size()) {
            std::swap(a, n);
        }
        az = a.size();
        nz = n.size();
        for (std::size_t i{0}, j{0};i < az;++i) {
            res.push_back(a[i]);
            if (j < nz) {
                res.push_back(n[j]);
            }
        }
        return res;
    }
};