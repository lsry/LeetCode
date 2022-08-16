#include <vector>
using std::vector;
#include <stack>
using std::stack;
#include <string>
using std::string;


class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<std::pair<int, int>> execute;
        stack<int> times;
        for (string const &log : logs) {
            int num = 0;
            string start;
            int time = 0;
            int index = 0;
            int lz = log.size();
            while (index < lz && log[index] != ':') {
                num = num * 10 + (log[index] - '0');
                ++index;
            }
            ++index;
            while (index < lz && log[index] != ':') {
                start.push_back(log[index]);
                ++index;
            }
            ++index;
            while (index < lz) {
                time = time * 10 + (log[index] - '0');
                ++index;
            }
            if (start[0] == 's') {
                execute.push({num, time});
                times.push(0);
            } else {
                std::pair<int, int> cur = execute.top();
                execute.pop();
                int otherTime = times.top();
                times.pop();
                int exeTime = time - cur.second + 1 - otherTime;
                res[cur.first] += exeTime;
                if (!times.empty()) {
                    int prev = times.top();
                    times.pop();
                    prev += time - cur.second + 1;
                    times.push(prev);
                }
            }
        }
        return res;
    }
};