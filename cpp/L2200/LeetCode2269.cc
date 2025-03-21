#include <cmath>
#include <string>
using std::string;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string ns = std::to_string(num);
        unsigned long long int x{0};
        int ans{0};
        unsigned long long int mod = std::pow(10, k );
        for (int i = 0, j{0};j < ns.size();++j) {
            x = x * 10 + (ns[j] - '0');
            x = x % mod;
            if (j - i + 1 == k) {
                if (x != 0 && num % x == 0) {
                    ++ans;
                    
                }
                ++i;
            }
        }  
        return ans;    
    }
};

int main() {
    Solution s;
    s.divisorSubstrings(430043, 2);
}