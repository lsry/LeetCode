#include <vector>
using std::vector;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> r;
        if (finalSum % 2 != 0) {
            return r;
        }   
        int x{2};
        for (;finalSum - x > x;x += 2) {
            r.push_back(x);
            finalSum -= x;
        }
        r.push_back(finalSum);
        return r;
    }
};