#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        std::sort(logs.begin(), logs.end(), [](vector<int> const &a, vector<int> const &b) {
            return a[1] < b[1];
        });
        int N = queries.size();
        vector<int> ids(N);
        std::iota(ids.begin(), ids.end(), 0);
        std::sort(ids.begin(), ids.end(), [&](int x, int y) {
            return queries[x] < queries[y];
        });
        std::unordered_map<int, int> appears;
        int LN = logs.size();
        int left{0}, right{0};
        vector<int> ans(N, 0);
        for (int id : ids) {
            while (right < LN && logs[right][1] <= queries[id]) {
                appears[logs[right][0]]++;
                ++right;
            }
            while (left < LN && logs[left][1] < queries[id] - x) {
                appears[logs[left][0]]--;
                if (appears[logs[left][0]] <= 0) {
                    appears.erase(logs[left][0]);
                }
                ++left;
            }
            ans[id] = n - appears.size();
        }
        return ans;
    }
};
