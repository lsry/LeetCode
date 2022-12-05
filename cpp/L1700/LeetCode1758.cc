#include <string>
using std::string;

class Solution {
public:
    int minOperations(string s) {
        string str{"10"};
        int count1{0}, count2{0};
        int hope1{0}, hope2{1};
        for (char const c : s) {
            if (c != str[hope1]) {
                ++count1;
            }
            if (c != str[hope2]) {
                ++count2;
            }
            hope1 = 1 - hope1;
            hope2 = 1 - hope2;
        }
        return std::min(count1, count2);
    }
};