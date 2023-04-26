#include <string>
using std::string;
#include <array>

struct Date {
    int month, day;
    Date(string date) {
        month = (date[0] - '0') * 10 + (date[1] - '0');
        day = (date[3] - '0') * 10 + (date[4] - '0');
    }
};


class Solution {
    constexpr static std::array<int, 12> monthOfDays{{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        if (arriveAlice > arriveBob) {
            return countDaysTogether(arriveBob, leaveBob, arriveAlice, leaveAlice);
        }
        if (leaveAlice < arriveBob) {
            return 0;
        }
        Date beginDate(arriveBob), endDate(leaveAlice <= leaveBob ? leaveAlice : leaveBob);
        int days{0};
        if (endDate.month > beginDate.month) {
            days += monthOfDays[beginDate.month - 1] - beginDate.day + 1;
        }
        for (int m = beginDate.month + 1;m < endDate.month;++m) {
            days += monthOfDays[m - 1];
        }
        days += endDate.day;
        if (beginDate.month == endDate.month) {
            days = days - beginDate.day + 1;
        }
        return days;
    }
};