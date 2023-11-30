#include <array>
#include <string>
#include <unordered_map>
using std::string;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        std::array<int, 26> a1{0}, a2{0};
        for (char const c : word1) {
            a1[c - 'a'] += 1;
        }
        for (char const c : word2) {
            a2[c - 'a'] += 1;
        }
        for (int i = 0;i < 26;++i) {
            if (a1[i] == 0 && a2[i] != 0 || a1[i] != 0 && a2[i] == 0) {
                return false;
            }
        }
        std::unordered_map<int, int> m1, m2;
        for (int x : a1) {
            if (x == 0) {
                continue;
            }
            m1[x] += 1;
        }
        for (int y : a2) {
            if (y == 0) {
                continue;
            }
            m2[y] += 1;
        }
        if (m1.size() != m2.size()) {
            return false;
        }
        for (auto const &[k1, v1] : m1) {
            if (m2[k1] != v1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    s.closeStrings("abc", "cba");
}