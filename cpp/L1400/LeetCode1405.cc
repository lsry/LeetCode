#include <string>
using std::string;

#include <vector>
using std::vector;

#include <utility>
using std::pair;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        vector<pair<int, char>> vec{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (vec[0].first + vec[1].first + vec[2].first > 0) {
            std::sort(vec.begin(), vec.end(), 
                     [](const pair<int, char> &a, const pair<int, char> &b){return a.first > b.first;});
            bool next = false;
            for (pair<int, char> &p : vec) {
                if (p.first <= 0) {
                    continue;
                }
                if (res.size() > 1 && res[res.size() - 1] == p.second && res[res.size() - 2] == p.second) {
                    continue;
                }
                res += p.second;
                p.first -= 1;
                next = true;
                break;
            }
            if (!next) {
                break;
            }
        }
        return res;
    }

private:
};