#include <vector>
using std::vector;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        if (n == 0 || requests.empty()) {
            return 0;
        }
        int sz = requests.size();
        int limit = 1 << sz;
        int ans = 0;
        for (int i = 1;i < limit;++i) {
            ans = std::max(ans, verify(requests, i, n));
        }
        return ans;
    }

private:
    int verify(vector<vector<int>>& requests, int choice, int n) {
        vector<int> flags(n, 0);
        int res = 0;
        int sz = requests.size();
        for (int i = 0;i < sz;++i) {
            if (((1 << i) & choice) != 0) {
                ++res;
                flags[requests[i][0]]--;
                flags[requests[i][1]]++;
            }
        }
        for (int &flag : flags) {
            if (flag != 0) {
                return 0;
            }
        }
        return res;
    }
};