#include <algorithm>
#include <array>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        std::array<int, 10> digitCount{0};
        for (int digit : digits) {
            digitCount[digit] ++;
        }
        vector<int> ans;
        std::array<int, 10> flag{0};
        for (int i = 100;i < 1000;i += 2) {
            std::fill(flag.begin(), flag.end(), 0);
            flag[i % 10]++;
            flag[i /10 % 10] ++;
            flag[i / 100]++;
            bool exist{true};
            for (int x = 0;x < 10;++x) {
                if (flag[x] > digitCount[x]) {
                    exist = false;
                    break;
                }
            }
            if (exist) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};