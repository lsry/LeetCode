#include <string>
using std::string;

class Solution {
public:
    int bestClosingTime(string customers) {
        int Y{0};
        for (char c : customers) {
            if (c == 'Y') {
                ++Y;
            }
        }
        int N{0};
        int time{0}, cost{Y};
        int i{1};
        for (char c : customers) {
            if (c == 'Y') {
                --Y;
            } else {
                ++N;
            }
            int ct{N + Y};
            if (ct < cost) {
                time = i;
                cost = ct;
            }
            ++i;
        }
        return time;
    }
};
