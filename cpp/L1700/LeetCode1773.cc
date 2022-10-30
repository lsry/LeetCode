#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int key = 0;
        if (ruleKey == "color") {
            key = 1;
        } else if (ruleKey == "name") {
            key = 2;
        }
        int ans{0};
        for (vector<string> &item : items) {
            if (item[key] == ruleValue) {
                ++ans;
            }
        }
        return ans;
    }
};