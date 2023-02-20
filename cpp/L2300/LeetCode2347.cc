#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>

class Solution {
    bool flush(vector<char> &suits) {
        for (int i = 1;i < 5;++i) {
            if (suits[i] != suits[0]) {
                return false;
            }
        }
        return true;
    }
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (flush(suits)) {
            return "Flush";
        }
        std::sort(ranks.begin(), ranks.end());
        int same{1};
        for (int i = 0, j = 0;i < 5;) {
            j = i;
            while (j < 5 && ranks[j] == ranks[i]) {
                ++j;
            }
            same = std::max(same, j - i);
            i = j;
        }
        switch (same) {
            case 4:
            case 3:
                return "Three of a Kind";
            case 2:
                return "Pair";
            default:
                return "High Card";
        }
        return "";
    }
};