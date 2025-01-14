#include <algorithm>
#include <string>
using std::string;

class Solution {
    string toBinary(int x) {
        string b;
        while (x != 0) {
            b.push_back(x % 2 == 0 ? '0' : '1');
            x /= 2;
        }
        std::reverse(b.begin(), b.end());
        return b;
    }
public:
    string convertDateToBinary(string date) {
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8);
        int yearI = std::stoi(year);
        int monthI = std::stoi(month);
        int dayI = std::stoi(day);
        string yearB = toBinary(yearI);
        string monthB = toBinary(monthI);
        string dayB = toBinary(dayI);
        return yearB + "-" + monthB + "-" + dayB;
    }
};