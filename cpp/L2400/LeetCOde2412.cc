#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        vector<int> minus, plus;
        for (int i = 0;i < transactions.size();++i) {
            if (transactions[i][1] >= transactions[i][0]) {
                plus.push_back(i);
            } else {
                minus.push_back(i);
            }
        }      
        std::sort(minus.begin(), minus.end(), [&](int x, int y) {
            return transactions[x][1] < transactions[y][1];
        });
        std::sort(plus.begin(), plus.end(), [&](int x, int y) {
            return transactions[x][0] > transactions[y][0];
        });
        long long ans{0LL};
        long long start{0LL};
        for (int x : minus) {
            start -= transactions[x][0];
            ans = std::min(ans, start);
            start += transactions[x][1];
        }
        for (int x : plus) {
            start -= transactions[x][0];
            ans = std::min(ans, start);
            start += transactions[x][1];
        }
        return -1 * ans;
    }
};