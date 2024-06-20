#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
    bool checkChildSeriel(string const &verified, string const &target) {
        int VN = verified.size(), TN = target.size();
        if (VN > TN) {
            return false;
        } else if (VN == TN) {
            return verified == target;
        }
        int v = 0, t = 0;
        for (;v < VN && t < TN;++v, ++t) {
            while (t < TN && verified[v] != target[t]) {
                ++t;
            }
            if (t >= TN) {
                break;
            }
        }
        return v == VN;
    }
public:
    int findLUSlength(vector<string>& strs) {
        int N = strs.size();
        int ans{0};
        for (int i = 0;i < N;++i) {
            bool flag{true};
            for (int j = 0;j < N;++j) {
                if (i != j && checkChildSeriel(strs[i], strs[j])) {
                        flag = false;
                        break;
                    } 
            }
            if (flag) {
                ans = std::max(ans, static_cast<int>(strs[i].size()));
            }
        }
        return ans == 0 ? -1 :ans;
    }
};

int main() {
    Solution s;
    vector<string> v{"abcabc","abcabc","abcabc","abc","abc","cca"};
    s.findLUSlength(v);
}