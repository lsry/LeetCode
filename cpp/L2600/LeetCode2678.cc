#include <numeric>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        return std::accumulate(details.begin(), details.end(), 0, [](int count, string const &p) {
            int age = (p[11] - '0') * 10 + (p[12] - '0');
            return age > 60 ? count + 1 : count;
        });
    }
};