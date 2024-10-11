#include <cstdlib>
#include <vector>
using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        int gasSum = 0, costSum{0}, diffSum{0};
        int start = -1;
        for (int i = 0;i < N;++i) {
            diffSum += gas[i] - cost[i];
            gasSum += gas[i];
            costSum += cost[i];
            if (diffSum < 0) {
                start = -1;
                diffSum = 0;
            } else if (start == -1) {
                start = i;
            }
        }
        return gasSum >= costSum ? start : -1;
    }
};