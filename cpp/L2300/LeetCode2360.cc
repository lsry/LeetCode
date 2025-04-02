#include <vector>
using std::vector;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int N =edges.size();
        vector<int> distance(N, -1);
        int ans{-1};
        int current{0};
        for (int i = 0;i < N;++i) {
            if (distance[i] != -1) {
                continue;
            }
            int j = i;
            int start = current;
            while (j != -1) {
                ++current;
                if (distance[j] != -1) {
                    if (distance[j] > start) {
                        ans = std::max(ans, current - distance[j]);
                    }
                    break;
                }
                distance[j] = current;
                j = edges[j];
            }
        }
        return ans;
    }
};

int main() {
    vector<int> edges{49,29,24,24,-1,-1,-1,2,23,-1,44,47,52,49,9,31,40,34,-1,53,33,-1,2,-1,18,31,0,9,47,35,-1,-1,-1,-1,4,12,14,19,-1,4,4,43,25,11,54,-1,25,39,17,-1,22,44,-1,44,29,50,-1,-1};
    Solution s;
    s.longestCycle(edges);
}