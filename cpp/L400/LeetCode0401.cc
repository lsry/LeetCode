#include <string>
using std::string;
#include <vector>
using std::vector;

class Solution {
    constexpr static int HEAD_MASK{0b1111000000};
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> r;
        for (int i = 0;i < 1024;++i) {
            int hour{0}, minute{0};
            int one{0};
            for (int j = 0;j < 6;++j) {
                if (((i >> j) & 1) == 0) {
                    minute = minute * 2;
                } else {
                    minute = minute * 2 + 1;
                    ++one;
                }
            }
            for (int j = 6;j < 10;++j) {
                if (((i >> j) & 1) == 0) {
                    hour *= 2;
                } else {
                    hour = hour * 2 + 1;
                    ++one;
                }
            }
            if (one != turnedOn || hour > 11 || minute > 59) {
                continue;
            }
            string t;
            t += std::to_string(hour) + ":";
            if (minute < 10) {
                t += "0" + std::to_string(minute);
            } else {
                t += std::to_string(minute);
            }
            r.push_back(t);
        }
        return r;
    }
};
