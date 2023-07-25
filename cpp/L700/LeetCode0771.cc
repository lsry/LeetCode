#include <string>
using std::string;

#include <unordered_set>

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        std::unordered_set<char> st;
        for (char c : jewels) {
            st.emplace(c);
        }
        int ans{0};
        for (char c : stones) {
            if (st.find(c) != st.end()) {
                ++ans;
            }
        }
        return ans;
    }
};