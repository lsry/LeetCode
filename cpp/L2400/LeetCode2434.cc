#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using std::string;

class Solution {
public:
    string robotWithString(string s) {
        auto f{[](std::pair<char, int> const &p1, std::pair<char, int> const &p2) {
            return p1.first == p2.first ? p1.second > p2.second : p1.first > p2.first;
        }};
        std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(f)> pq;
        std::stack<char> st;
        for (int i = 0;i < s.size();++i) {
            pq.push(std::pair<char, int>(s[i], i));
        }
        string r;
        int cursor = -1;
        while (!pq.empty()) {
            while (!pq.empty() && pq.top().second <= cursor) {
                pq.pop();
            }
            if (pq.empty()) {
                break;
            }
            while (!st.empty() && st.top() <= pq.top().first) {
                r.push_back(st.top());
                st.pop();
            }   
            r.push_back(pq.top().first);
            for (int i = cursor + 1;i < pq.top().second;++i) {
                st.push(s[i]);
            }
            cursor = pq.top().second;
            pq.pop();
        }
        while (!st.empty()) {
            r.push_back(st.top());
            st.pop();
        }
        return r;
    }
};