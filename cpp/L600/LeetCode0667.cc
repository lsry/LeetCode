#include <vector>
using std::vector;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        res.push_back(1);
        int l = 2, r = n;
        bool dir = false;
        while (k > 1) {
            if (!dir) {
                res.push_back(r);
                --r;
            } else {
                res.push_back(l);
                ++l;
            }
            dir = !dir;
            --k;
        }
        while (l <= r) {
            if (dir) {
                res.push_back(r);
                --r;
            } else {
                res.push_back(l);
                ++l;
            }
        }
        return res;
    }
};