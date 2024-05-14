#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int timeP{0}, timeM{0}, timeG{0};
        int ans{0};
        int N = garbage.size();
        for (int i = 0;i < N;++i) {
            int P{0}, M{0}, G{0};
            for (char const c : garbage[i]) {
                if (c == 'P') {
                    ++P;
                } else if (c == 'M') {
                    ++M;
                } else {
                    ++G;
                }
            }
            if (P > 0) {
                ans += P + timeP;
                timeP = 0;
            }
            if (M > 0) {
                ans += M + timeM;
                timeM = 0;
            }
            if (G > 0) {
                ans += G + timeG;
                timeG = 0;
            }
            if (i < N - 1) {
                timeG += travel[i];
                timeM += travel[i];
                timeP += travel[i];
            }
        }
        return ans;
    }
};