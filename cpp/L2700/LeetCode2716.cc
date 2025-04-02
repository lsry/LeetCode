#include <string>
#include <vector>
using std::string;

class Solution {
public:
    int minimizedStringLength(string s) {
        std::vector<bool> flag(26, false);
        int ans{0};
        for (char c : s) {
            int x = c - 'a';
            if (!flag[x]) {
                ++ans;
                flag[x] = true;
            }
        }      
        return ans;
    }
};