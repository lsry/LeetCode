#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int hurryTime{std::numeric_limits<int>::max()};
        int LN = landStartTime.size(), WN = waterDuration.size();
        for (int i = 0;i < LN;++i) {
            for (int j = 0;j < WN;++j) {
                if (landStartTime[i] <= waterStartTime[j]) {
                    int time = landStartTime[i] + landDuration[i] <= waterStartTime[j] ? waterStartTime[j] + waterDuration[j]
                        : landStartTime[i] + landDuration[i] + waterDuration[j];
                    hurryTime = std::min(hurryTime, time);
                } else {
                    int time = waterStartTime[j] + waterDuration[j] <= landStartTime[i] ? landStartTime[i] + landDuration[i]
                        : waterStartTime[j] + waterDuration[j] + landDuration[i];
                    hurryTime = std::min(hurryTime, time);
                }
            }
        }
        return hurryTime;
    }
};
