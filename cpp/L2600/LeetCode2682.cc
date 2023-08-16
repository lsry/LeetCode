#include <vector>
using std::vector;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> flags(n, false);
        for (int i{0},j{1};!flags[i];i = (i + j * k) % n, j = j + 1) {
            flags[i] = true;
        }        
        vector<int> r;
        for (int i = 0;i < n;++i) {
            if (!flags[i]) {
                r.push_back(i + 1);
            }
        }
        return r;
    }
};