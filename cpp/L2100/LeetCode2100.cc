#include <vector>
using std::vector;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int sz = security.size();
        vector<int> decr(sz), incr(sz);
        decr[0] = 1;
        for (int i = 1;i < sz;++i) {
            if (security[i] <= security[i - 1]) {
                decr[i] = decr[i - 1] + 1;
            } else {
                decr[i] = 1;
            }
        }      
        incr[sz - 1] = 1;
        for (int i = sz - 2;i >= 0;--i) {
            if (security[i] <= security[i + 1]) {
                incr[i] = incr[i + 1] + 1;
            } else {
                incr[i] = 1;
            }
        }
        vector<int> res;
        for (int i = 0;i < sz;++i) {
            if (decr[i] >= time + 1 && incr[i] >= time + 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};