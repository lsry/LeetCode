#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int IMAX = std::numeric_limits<int>::max();
        int t1{IMAX}, t2{IMAX};
        int r1{IMAX}, r2{IMAX};
        int LN = landStartTime.size(), WN = waterStartTime.size();
        for (int i = 0;i < LN;++i) {
            t1 = std::min(t1, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0;i < WN;++i) {
            t2 = std::min(t2, waterStartTime[i] + waterDuration[i]);
            r1 = std::min(r1, waterStartTime[i] <= t1 ? t1 + waterDuration[i] : waterStartTime[i] + waterDuration[i]);
        }
        for (int i = 0;i < LN;++i) {
            r2 = std::min(r2, landStartTime[i] <= t2 ? t2 + landDuration[i] : landStartTime[i] + landDuration[i]);
        }
        return std::min(r1, r2);
    }
};
