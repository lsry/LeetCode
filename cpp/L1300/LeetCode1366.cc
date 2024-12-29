#include <algorithm>
#include <array>
#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        std::array<std::array<int, 26>, 26> arr{};
        string r;
        for (string const &vote : votes) {
            for (int i = 0;i < vote.size();++i) {
                arr[vote[i] - 'A'][i] += 1;
                if (r.find(vote[i]) == std::string::npos) {
                    r.push_back(vote[i]);
                }
            }
        }
        std::sort(r.begin(), r.end(), [&](char const c1, char const c2) {
            for (int i = 0;i < votes[0].size();++i) {
                if (arr[c1 - 'A'][i] != arr[c2 - 'A'][i]) {
                    return arr[c1 - 'A'][i] > arr[c2 - 'A'][i];
                }
            }
            return c1 < c2;
        });
        return r;
    }
};