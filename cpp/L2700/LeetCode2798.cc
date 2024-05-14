#include <algorithm>
#include <iterator>
#include <vector>
using std::vector;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        std::sort(hours.begin(), hours.end());
        auto it{std::lower_bound(hours.begin(), hours.end(), target)};
        return std::distance(it, hours.end());
    }
};