#include <vector>
using std::vector;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int N = days.size();
        vector<int> totals(N + 1, 0);
        for (int i = 1;i <= N;++i) {
            totals[i] = totals[i - 1] + costs[0];
            for (int j = i;j - 1 >= 0 && days[i - 1] - days[j - 1] + 1 <= 30;--j) {
                int dayCount = days[i - 1] - days[j - 1] + 1;
                if (dayCount <= 7) {
                    totals[i] = std::min(totals[i], totals[j - 1] + costs[1]);
                } 
                totals[i] = std::min(totals[i], totals[j - 1] + costs[2]);
            }
        }
        return totals[N];
    }
};