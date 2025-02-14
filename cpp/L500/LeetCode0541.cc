#include <string>
using std::string;

class Solution {
    void reverseStrIter(string &s, int start, int end) {
        while (start < end) {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;
            ++start;
            --end;
        }
    }
public:
    string reverseStr(string s, int k) {
        int N = s.size();
        for (int i = 0;i < N;i += 2 * k) {
            int end = std::min(i + k, N);
            reverseStrIter(s, i, end - 1);
        }
        return s;
    }
};