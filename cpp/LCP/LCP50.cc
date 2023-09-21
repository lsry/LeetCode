#include <vector>
using std::vector;

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (vector<int> const &p : operations) {
            gem[p[1]] += gem[p[0]] / 2;
            gem[p[0]] -= gem[p[0]] / 2;
        }
        int c1{gem[0]}, c2{gem[0]};
        for (int g : gem) {
            if (c1 > g) {
                c1 = g;
            }
            if (c2 < g) {
                c2 = g;
            }
        }
        return c2 - c1;
    }
};