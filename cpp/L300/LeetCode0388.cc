#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    int lengthLongestPath(string input) {
        int maxLength = 0;
        int curLength = 0;
        int chart = 0;
        bool fileFlag = false;
        unordered_map<int, int> map;
        std::size_t sz = input.size();
        for (std::size_t i{0};i <= sz;++i) {
            if (i >= sz || input[i] == '\n') {
                if (fileFlag) {
                    curLength += chart;
                    maxLength = std::max(maxLength, curLength + map[chart - 1]);
                } else {
                    map[chart] = curLength + map[chart - 1];
                }
                chart = 0;
                fileFlag = false;
                curLength = 0;
            } else if (input[i] == '.') {
                fileFlag = true;
                curLength++;
            } else if (input[i] == '\t') {
                ++chart;
            } else {
                ++curLength;
            }
        }
        return maxLength;
    }
};