#include <string>
using std::string;

class Solution {
    bool isLeafYear(int year) {
        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    }

    string getDayOfWeekName(int x) {
        switch (x) {
            case 0:
               return "Thursday";
            case 1:
               return "Friday";
            case 2:
               return "Saturday";
            case 3:
               return "Sunday";
            case 4:
               return "Monday";
            case 5:
               return "Tuesday";
            case 6:
               return "Wednesday";
        }
        return "";
    }
public:
    string dayOfTheWeek(int day, int month, int year) {
        int days{0};
        for (int y{1970};y < year;++y) {
            if (isLeafYear(y)) {
                days += 366;
            } else {
                days += 365;
            }
        }
        for (int m{1};m < month;++m) {
            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
                days += 31;
            } else if (m == 4 || m == 6 || m == 9 || m == 11) {
                days += 30;
            } else if (isLeafYear(year)) {
                days += 29;
            } else {
                days += 28;
            }
        }
        days += day;
        return getDayOfWeekName((days - 1) % 7);
    }
};