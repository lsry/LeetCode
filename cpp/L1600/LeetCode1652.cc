#include <vector>
using std::vector;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int nz = code.size();
        if (k == 0) {
            return vector<int>(nz, 0);
        }
        vector<int> res;
        if (k < 0) {
            k = -k;
            int sum = 0;
            for (int i = 1;i <= k;++i) {
                sum += code[nz - i];
            }
            for (int i = nz - k, j = nz - 1, m = 0;m < nz;++m) {
                res.push_back(sum);
                sum -= code[i];
                i = (i + 1) % nz;
                j = (j + 1) % nz;
                sum += code[j];
            }
        } else {
            int sum = 0;
            for (int i = 1;i <= k;++i) {
                sum += code[i];
            }
            for (int i = 1, j = k, m = 0;m < nz;++m) {
                res.push_back(sum);
                sum -= code[i];
                i = (i + 1) % nz;
                j = (j + 1) % nz;
                sum += code[j];
            }
        }
        return res;
    }
};