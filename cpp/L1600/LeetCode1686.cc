#include <vector>
using std::vector;
#include <algorithm>
#include <numeric>

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        std::size_t N{aliceValues.size()};
        vector<int> indics(N, 0);
        std::iota(indics.begin(), indics.end(), 0);
        std::sort(indics.begin(), indics.end(), [&](int a, int b) {
            return aliceValues[a] + bobValues[a] > aliceValues[b] + bobValues[b];
        });
        int alice{0}, bob{0};
        for (std::size_t i{0};i < N;++i) {
            if (i % 2 == 0) {
                alice += aliceValues[indics[i]];
            } else {
                bob += bobValues[indics[i]];
            }
        }
        return alice < bob ? -1 : (alice == bob ? 0 : 1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> alice{1,3}, bob{2,1};
    Solution s;
    s.stoneGameVI(alice, bob);
    return 0;
}
