#include <vector>
using std::vector;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int flow{-1}, fhigh{-1};
        int slow{-1}, shigh{-1};
        int N = values.size();
        int beforeMax = -0x3f3f3f;
        int ans = -0x3f3f3f;
        for (int i = 0;i < N;++i) {
            ans = std::max(ans, beforeMax + values[i] - i);
            beforeMax = std::max(beforeMax, values[i] + i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{2,2,2};
    s.maxScoreSightseeingPair(v);
}