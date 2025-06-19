#include <queue>
#include <string>
#include <utility>
#include <vector>
using std::string;

class Solution {
public:
    string clearStars(string s) {
        int N = s.size();
        std::vector<bool> deleted(N, false);
        auto f{[](std::pair<char, int> const &p1, std::pair<char, int> const &p2) {
            return p1.first == p2.first ? p1.second < p2.second : p1.first > p2.first;
        }};
        std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(f)> pq;
        for (int i = 0;i < N;++i) {
            if (s[i] != '*') {
                pq.push(std::pair<char, int>(s[i], i));
            } else if (!pq.empty()) {
                deleted[pq.top().second] = true;
                pq.pop();
            }
        }
        string r;
        for (int i = 0;i < N;++i) {
            if (s[i] != '*' && !deleted[i]) {
                r.push_back(s[i]);
            }
        }
        return r;
    }
};