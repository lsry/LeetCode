#include <vector>
using std::vector;

class Solution {
    long long int getNums(int num) {
        long long int ans{0};
        for (int x{1}, step{1};x <= num;x *= 4) {
            int right = std::min(x * 4 - 1, num);
            ans += 1LL * step * (right - x + 1);
            ++step;
        }
        return ans;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long int ans{0};
        for (vector<int> const & q : queries) {
            ans += (getNums(q[1]) - getNums(q[0] - 1) + 1) / 2;
        }
        return ans;
    }
};