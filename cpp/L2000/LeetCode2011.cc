#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans{0};
        for (string const &oper : operations) {
            if (oper[1] == '+') {
                ++ans;
            } else {
                --ans;
            }
        }
        return ans;
    }
};
