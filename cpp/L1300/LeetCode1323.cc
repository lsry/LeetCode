#include <string>
class Solution {
public:
    int maximum69Number (int num) {
        std::string ns{std::to_string(num)};
        for (char &c : ns) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return std::stoi(ns);
    }
};