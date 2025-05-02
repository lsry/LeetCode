#include <algorithm>
#include <deque>
#include <functional>
#include <vector>
using std::vector;

class Solution {
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        std::deque<int> dq;
        int tn = tasks.size();
        for (int i = tn - k, j = 0;i < tn;++i) {
            while (j < k && workers[j] + strength >= tasks[i]) {
                dq.push_front(workers[j]);
                ++j;
            }
            if (dq.empty()) {
                return false;
            }
            if (dq.back() >= tasks[i]) {
                dq.pop_back();
            } else if (pills == 0) {
                return false;
            } else {
                --pills;
                dq.pop_front();
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        std::sort(tasks.begin(), tasks.end(), std::greater<int>());
        std::sort(workers.begin(), workers.end(), std::greater<int>());

        int low = 0, high = std::min(tasks.size(), workers.size());
        int ans{0};
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(tasks, workers, pills, strength, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};