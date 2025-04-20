#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        std::unordered_map<int, int> numMap;
        int ans{0};
        for (int answer : answers) {
            numMap[answer] += 1;
        }
        for (auto const &[num, count] : numMap) {
            int mod = num + 1;
            int remaind = count % mod;
            if (remaind == 0) {
                ans += count;
            } else {
                ans += count + mod - remaind;
            }
        }
        return ans;
    }
};