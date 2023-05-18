#include <string>
using std::string;

class Solution {
public:
    int countTime(string time) {
        int count{1};
        if (time[0] == '?') {
            if (time[1] == '?') {
                count = 24;
            } else if (time[1] < '4') {
                count = 3;
            } else {
                count = 2;
            }
        } else if (time[1] == '?') {
            count = time[0] == '2' ? 4 : 10;
        }
        if (time[3] == '?') {
            count *= 6;
        }
        if (time[4] == '?') {
            count *= 10;
        }
        return count;
    }
};