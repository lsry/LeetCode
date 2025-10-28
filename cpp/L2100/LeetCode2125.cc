#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans{0};
        int last{0};
        for (string const &s : bank) {
            int count{0};
            for (char c : s) {
                if (c == '1') {
                    ++count;
                }
            }
            ans += last * count;
            if (count > 0) {
                last = count;
            }
        }
        return ans;
    }
};
