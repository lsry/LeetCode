#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long int mv{*std::max_element(milestones.begin(), milestones.end())};
        long long int sv{std::accumulate(milestones.begin(), milestones.end(), 0LL)};
        return mv > sv - mv + 1 ? 2 * (sv - mv) + 1 : sv;
    }
};