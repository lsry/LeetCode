#include <vector>
using std::vector;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_attitude{0}, cur_attitude{0};
        for (int attitude : gain) {
            cur_attitude += attitude;
            max_attitude = std::max(cur_attitude, max_attitude);
        }
        return max_attitude;
    }
};