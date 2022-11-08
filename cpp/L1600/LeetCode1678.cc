#include <string>
using std::string;

class Solution {
public:
    string interpret(string command) {
        string res;
        for (std::string::iterator it{command.begin()};it != command.end();++it) {
            if (*it == 'G') {
                res.push_back('G');
            } else if (*it == '(') {
                if (*(it + 1) == ')') {
                    res.push_back('o');
                    ++it;
                } else {
                    res.append("al");
                    it = it + 3;
                }
            }
        }
        return res;
    }
};