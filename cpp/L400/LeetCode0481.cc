#include <deque>

class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) {
            return 1;
        }
        std::deque<int> q;
        q.push_back(2);
        int ans = 1;
        for (int x = 4;x <= n;) {
            int h = q.front();
            int t = 3 - q.back();
            if (t == 1) {
                ans += h;
                if (x + h > n) {
                    if (x + h > n + 1) {
                        ans--;
                    }
                }
            }
            q.push_back(t);
            if (h == 2) {
                q.push_back(t);
            } 
            x += h;
            q.pop_front();
        }
        return ans;
    }
};