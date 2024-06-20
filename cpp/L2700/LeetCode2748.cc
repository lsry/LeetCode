#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans{0};
        for (auto one{nums.begin()};one != nums.end();++one) {
            for (auto two{one + 1};two != nums.end();++two) {
                int n2 = *two % 10;
                int n1 = *one;
                while (n1 >= 10) {
                    n1 = n1 / 10;
                }
                if (std::gcd(n1, n2) == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};