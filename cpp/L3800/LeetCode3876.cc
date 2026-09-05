#include <vector>
using std::vector;
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCount{0}, evenCount{0};
        int minOdd{-1}, minEven{-1};
        for (int num : nums1) {
            if (num % 2 == 0) {
                ++evenCount;
                if (minEven == -1 || num < minEven) {
                    minEven = num;
                }
            } else {
                ++oddCount;
                if (minOdd == -1 || num < minOdd) {
                    minOdd = num;
                }
            }
        }
        if (oddCount == 0 || evenCount == 0) {
            return true;
        }
        return minOdd < minEven;
    }
};
