#include <string>
using std::string;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <unordered_map>
using std::unordered_map;
#include <queue>
using std::queue;

class Solution {
private:
    static int const GEN_LEN{8};
    int diff(string const &s1, string const &s2) {
        int dis = 0;
        for (std::size_t i{0};i < GEN_LEN;++i) {
            if (s1[i] != s2[i]) {
                ++dis;
            }
        }
        return dis;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) {
            return 0;
        }
        set<string> searched;
        int dis = 0;
        queue<string> nextStr;
        nextStr.push(start);
        while (!nextStr.empty()) {
            std::size_t qz = nextStr.size();
            for (std::size_t i{0};i < qz;++i) {
                string curStr = nextStr.front();
                nextStr.pop();
                if (curStr == end) {
                    return dis;
                }
                if (searched.find(curStr) != searched.end()) {
                    continue;
                }
                searched.emplace(curStr);
                for (string &s : bank) {
                    if (searched.find(s) == searched.end() && diff(s, curStr) == 1) {
                        nextStr.push(s);
                    }
                }
            }
            ++dis;
        }
        return -1;
    }
};