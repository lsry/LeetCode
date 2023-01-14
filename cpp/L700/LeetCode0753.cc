#include <unordered_set>
#include <string>
using std::string;
#include <cmath>

class Solution {
    std::unordered_set<int> set;
    int high;
    string ans;
    int k;

    void dfs(int node) {
        for (int x = 0;x < k;++x) {
            int next = node * 10 + x;
            if (set.find(next) == set.end()) {
                set.insert(next);
                dfs(next % high);
                ans += (x + '0');
            }
        }
    }
public:
    string crackSafe(int n, int k) {
        high = std::pow(10, n - 1);
        this->k = k;
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};