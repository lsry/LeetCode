#include <vector>
using std::vector;
#include <algorithm>

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end(), [](vector<int> const &m1, vector<int> const &m2) {
            return m1[0] == m2[0] ? m1[1] < m2[1] : m1[0] < m2[0];
        });
        int N = meetings.size();
        int ans{0};
        int lastEnd{0};
        for (int i = 0;i < N;) {
            ans += meetings[i][0] - lastEnd - 1;
            int nextEnd{meetings[i][1]};
            int j = i;
            while (j < N && meetings[j][0] <= nextEnd) {
                nextEnd = std::max(nextEnd, meetings[j][1]);
                ++j;
            }
            lastEnd = nextEnd;
            i = j;
        }
        if (days > lastEnd) {
            ans += days - lastEnd;
        }
        return ans;
    }
};