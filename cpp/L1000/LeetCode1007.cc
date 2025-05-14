#include <limits>
#include <vector>
using std::vector;

class Solution {
    int iter(vector<int>& tops, vector<int>& bottoms, int num) {
        int N = tops.size();
        int tn{0}, bn{0};
        for (int i = 0;i < N;++i) {
            if (tops[i] != num && bottoms[i] == num) {
                ++tn;
            } else if (tops[i] != num) {
                tn = -1;
                break;
            }
        }
        for (int i = 0;i < N;++i) {
            if (bottoms[i] != num && tops[i] == num) {
                ++bn;
            } else if (bottoms[i] != num) {
                bn = -1;
                break;
            }
        }
        if (tn == -1) {
            return bn;
        } else if (bn == -1) {
            return tn;
        } else {
            return std::min(tn, bn);
        }
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans{std::numeric_limits<int>::max()};
        for (int i = 1;i <= 6;++i) {
            int x = iter(tops, bottoms, i);
            if (x != -1) {
                ans = std::min(ans, x);
            }
        }
        return ans == std::numeric_limits<int>::max() ? -1 : ans;
    }
};