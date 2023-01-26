#include <string>
using std::string;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'z');
        int goal{26 * n};
        for (std::size_t i{0};i < n && goal > k;++i) {
            if (goal - k >= 25) {
                res[i] = 'a';
                goal -= 25;
            } else {
                int diff{goal - k};
                res[i] = static_cast<char>(res[i] - diff);
                goal -= diff;
            }
        }
        return res;
    }
};