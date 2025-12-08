#include <stack>
#include <string>
using std::string;

class Solution {
public:
    int countCollisions(string directions) {
        std::stack<char> dir;
        int ans{0};
        for (char c : directions) {
            if (c == 'R') {
                dir.push(c);
                continue;
            }
            if (c == 'S') {
                while (!dir.empty() && dir.top() == 'R') {
                    ++ans;
                    dir.pop();
                }
                dir.push(c);
                continue;
            }
            if (!dir.empty() && dir.top() == 'R') {
                while (!dir.empty() && dir.top() == 'R') {
                    ++ans;
                    dir.pop();
                }
                ++ans;
                dir.push('S');
            } else if (!dir.empty() && dir.top() == 'S') {
                ++ans;
            } else {
                dir.push(c);
            }
        }
        return ans;
    }
};
