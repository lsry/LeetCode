#include <vector>
using std::vector;
#include <queue>

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        std::queue<int> q;
        for (int x : nums) {
            q.push(x);
        }
        while (q.size() > 1) {
            bool minFlag(true);
            std::size_t qz{q.size()};
            for (std::size_t i{0};i < qz;i += 2) {
                int x1 = q.front();
                q.pop();
                int x2 = q.front();
                q.pop();
                if (minFlag) {
                    q.push(std::min(x1, x2));
                } else {
                    q.push(std::max(x1, x2));
                }
                minFlag = !minFlag;
            }
        }
        return q.front();
    }
};