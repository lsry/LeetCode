#include <algorithm>
#include <array>
#include <numeric>
#include <string>
using std::string;

class Solution {
public:
    int minimumPushes(string word) {
        std::array<int, 26> counts{0};
        for (char c : word) {
            counts[c - 'a']++;
        }
        std::array<int, 26> chars{0};
        std::iota(chars.begin(), chars.end(), 0);
        std::sort(chars.begin(), chars.end(), [&](int x, int y) {
            return counts[x] > counts[y];
        });
        int step{0};
        for (int i = 0, single = 1;i < 26;i += 8, single += 1) {
            for (int j = 0;j < 8 && i + j < 26;++j) {
                step += counts[chars[i + j]] * single;
            }
        }
        return step;
    }
};

int main() {
    string s = "xycdefghij";
    Solution st;
    st.minimumPushes(s);
}
