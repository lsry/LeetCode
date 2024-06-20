#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int N = people.size();
        int ans{0};
        std::sort(people.begin(), people.end());
        for (int left{0}, right{N};left < right;++left) {
            ans += 1;
            --right;
            while (right > left && people[right] + people[left] > limit) {
                ++ans;
                --right;
            }
        }
        return ans;
    }
};