#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int N = customers.size();
        int calm{0};
        for (int i = 0;i < N;++i) {
            if (grumpy[i] == 0) {
                calm += customers[i];
            }
        }
        int peopleCount{0}, relaxCount{0};
        int ans{0};
        for (int left{0}, right{0};right < N;++right) {
            peopleCount += customers[right];
            if (grumpy[right] == 0) {
                relaxCount += customers[right];
            }
            if (right - left + 1 > minutes) {
                peopleCount -= customers[left];
                if (grumpy[left] == 0) {
                    relaxCount -= customers[left];
                }
                ++left;
            }
            ans = std::max(ans, peopleCount + calm - relaxCount);
        }
        return ans;
    }
};