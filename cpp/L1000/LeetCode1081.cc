#include <string>
#include <vector>
using std::string;

class Solution {
public:
    string smallestSubsequence(string s) {
        string r;
        std::vector<bool> inStack(26, false);
        std::vector<int> lefts(26, 0);
        for (char c : s) {
            lefts[c - 'a']++;
        }
        for (char c : s) {
            int id = c - 'a';
            --lefts[id];
            if (inStack[id]) {
                continue;
            }
            while (!r.empty() && r.back() > c && lefts[r.back() - 'a'] > 0) {
                inStack[r.back() - 'a'] = false;
                r.pop_back();
            }
            r.push_back(c);
            inStack[id] = true;
        }
        return r;
    }
};
