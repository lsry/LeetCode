#include <set>
#include <string>
using std::string;
#include <vector>
using std::vector;
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        std::set<string> st;
        for (int i = 0;i < s.size();++i) {
            st.emplace(s.substr(0, i + 1));
        }
        int ans{0};
        for (string const &word : words) {
            if (st.contains(word)) {
                ++ans;
            }
        }
        return ans;
    }
};