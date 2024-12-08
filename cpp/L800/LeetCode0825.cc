#include <vector>
using std::vector;
#include <array>
using std::array;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        std::array<int, 121> ageMap{0};
        for (int age : ages) {
            ageMap[age] ++;
        }
        int quest{0};
        for (int i = 1;i <= 120;++i) {
            for (int j = i;j <= 120;++j) {
                bool ij = 1.0 * j <= 0.5 * i + 7 || j > i || (j > 100 && i < 100);
                bool ji = 1.0 * i <= 0.5 * j + 7 || i > j || (i > 100 && j < 100);
                if (!ij || !ji) {
                    if (i == j) {
                        quest += ageMap[i] * (ageMap[i] - 1);
                    } else {
                        quest += ageMap[i] * ageMap[j];
                    }
                }
            }
        }
        return quest;
    }
};