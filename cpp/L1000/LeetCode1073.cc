#include <vector>
using std::vector;
#include <algorithm>

/**
 * N = k * (-2) + m where m ∈ {0, 1}
 * k: includes all the higher digit, m: the lowest digit
 * when N ≡ 0 mod 2, then k = N / (-2)
 * when N ≡ 1 mod 2, then k = (N - 1) / (-2)
 */
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int c{0};
        for (int i = arr1.size() - 1, j = arr2.size() - 1;i >= 0 || j >= 0;--i, --j) {
            int x1 = i >= 0 ? arr1[i] : 0;
            int x2 = j >= 0 ? arr2[j] : 0;
            int s = x1 + x2 + c;
            res.push_back(s % 2 == 0 ? 0 : 1);
            c = (s % 2 == 0 ? s : s - 1) / (-2);
        }
        while (c != 0) {
            res.push_back(c % 2 == 0 ? 0 : 1);
            c = (c % 2 == 0 ? c : c - 1) / (-2);
        }
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};