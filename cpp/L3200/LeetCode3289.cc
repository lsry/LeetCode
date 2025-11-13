#include <cmath>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int N2 = nums.size();
        int N = N2 - 2;
        int numSum{0}, numSquare{0};
        for (int num : nums) {
            numSum += num;
            numSquare += num * num;
        }
        int nSum{N * (N - 1) / 2}, nSquare{(N - 1) * N * (2 * (N - 1) + 1) / 6};
        int aPlusb = numSum - nSum, aSquareb = numSquare - nSquare;
        int a = (2 * aPlusb + (int)std::sqrt(4 * aPlusb * aPlusb - 8 * (aPlusb * aPlusb - aSquareb))) / 4;
        return {a, aPlusb - a};
    }
};
