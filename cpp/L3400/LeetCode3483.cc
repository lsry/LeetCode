#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        std::unordered_set<int> nums;
        int N = digits.size();
        for (int i = 0;i < N;++i) {
            for (int j = 0;j < N;++j) {
                for (int k = 0;k < N;++k) {
                    if (i != j && j != k && i != k) {
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if (num >= 100 && num < 1000 && digits[k] % 2 == 0) {
                            nums.emplace(num);
                        }
                    }
                }
            }
        }
        return nums.size();
    }
};
