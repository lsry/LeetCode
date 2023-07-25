#include <vector>
using std::vector;

#include <algorithm>
#include <queue>

class Solution {
public:
    int halveArray(vector<int>& nums) {
        std::priority_queue<double, vector<double>, std::less<double>> pq;
        double sum{0.0};
        for (int num : nums) {
            sum += num;
            pq.push(num);
        }
        int step{0};
        double less_sum{0.0};
        while (less_sum * 2 < sum) {
            double num{pq.top()};
            pq.pop();
            ++step;
            less_sum += num / 2.0;
            pq.push(num / 2.0);
        }
        return step;
    }
};