#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int N = s.size();
        vector<string> r;
        for (int i = 0;i < N;i += k) {
            string t = s.substr(i, k);
            while (t.size() < k) {
                t.push_back(fill);
            }
            r.push_back(t);
        }      
        return r;
    }
};