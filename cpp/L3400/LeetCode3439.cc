#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int N = startTime.size();
        vector<int> gaps;
        int left{0};
        for (int i = 0;i < N;++i) {
            gaps.push_back(startTime[i] - left);
            if (i == N - 1) {
                gaps.push_back(eventTime - endTime[i]);
            }
            left = endTime[i];
        }
        int ans{0}, sum{0};
        N = gaps.size();
        for (int low{0}, i = 0;i < N;++i) {
            sum += gaps[i];
            while (i - low > k) {
                sum -= gaps[low];
                ++low;
            }
            ans = std::max(ans, sum);
        }
        return ans;
    }
};