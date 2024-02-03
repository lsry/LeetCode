#include <string>
using std::string;

class Solution {
    bool isLeafYear(int year) {
        return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
    }
public:
    int dayOfYear(string date) {
        int year{(date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0')};
        int month{(date[5] - '0') * 10 + (date[6] - '0')};
        int day{(date[8] - '0') * 10 + (date[9] - '0')};
        int ans{0};
        for (int i = 1;i < month;++i) {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                ans += 31;
            } else if (i == 4 || i == 6 || i == 9 || i == 11) {
                ans += 30;
            } else if (isLeafYear(year)) {
                ans += 29;
            } else {
                ans += 28;
            }
        }
        return ans + day;
    }
};