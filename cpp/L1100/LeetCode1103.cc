#include <cmath>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> r(num_people, 0);
        if (candies == 0 || num_people == 0) {
            return r;
        }
        long long int b4ac = 1LL + 8LL * candies;
        long long int r1 = static_cast<long long int>((std::sqrt(b4ac * 1.0) - 1) / 2.0);
        long long int preSum = r1 * (r1 + 1) / 2;
        long long int remain = candies - preSum;
        long long int turn = r1 / num_people;
        long long int turnRemain = r1 % num_people;
        for (int i = 0;i < num_people;++i) {
            long long int s = turn * (turn - 1) / 2;
            s = s * num_people + turn * (i + 1);
            if (i < turnRemain) {
                s += turn * num_people + i + 1;
            }
            r[i] = static_cast<int>(s);
        }
        r[turnRemain] += remain;
        return r;
    }
};

int main() {
    Solution s;
    s.distributeCandies(7, 4);
}