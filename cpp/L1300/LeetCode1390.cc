#include <cmath>
#include <vector>
using std::vector;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans{0};
        for (int num : nums) {
            int root = std::sqrt(num);
            int sum{0}, count{0};
            for (int i = 1;i <= root;++i) {
                if (num % i == 0) {
                    int a{num / i}, b{i};
                    if (a == b) {
                        ++count;
                        sum += a;
                    } else {
                        count += 2;
                        sum += a + b;
                    }
                }
            }
            if (count == 4) {
                ans += sum;
            }
        }
        return ans;
    }
};
