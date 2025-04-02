#include <string>
using std::string;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int N = s.size();
        int mx{0}, mn{0};
        for (int i = 0;i < N;++i) {
            int diff = s[i] == '(' ? 1 : -1;
            if (locked[i] == '1') {
                mx += diff;
                mn = std::max((i + 1) % 2, mn + diff);
            } else {
                mx += 1;
                mn = std::max((i + 1) % 2, mn - 1);
            }
            if (mx < mn) {
                return false;
            }
        }
        return mn == 0;
    }
};

int main() {
    Solution s;
    s.canBeValid("(((())(((())", "111111010111");
}