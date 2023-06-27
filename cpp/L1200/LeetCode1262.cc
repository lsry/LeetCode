#include <vector>
using std::vector;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int zero{0}, one{0}, two{0};
        for (int num : nums) {
            int nz{0}, no{0}, nt{0};
            if (num % 3 == 0) {
                nz = zero + num;
                no = one == 0 ? 0 : one + num;
                nt = two == 0 ? 0 : two + num;
            } else if (num % 3 == 1) {
                nz = two == 0 ? 0 : two + num;
                no = zero + num;
                nt = one == 0 ? 0 : one + num;
            } else {
                nz = one == 0 ? 0 : one + num;
                no = two == 0 ? 0 : two + num;
                nt = zero + num;
            }
            if (nz > zero) {
                zero = nz;
            }
            if (no > one) {
                one = no;
            }
            if (nt > two) {
                two = nt;
            }
        }
        return zero;
    }
};