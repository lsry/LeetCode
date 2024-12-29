#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        std::unordered_map<int, int> mp;
        for (int x : arr) {
            mp[x] += 1;
        }
        int len = arr.size();
        std::priority_queue<int, vector<int>, std::less<int>> pq;
        for (auto const &[k, v] : mp) {
            pq.push(v);
        }
        int deleted{0};
        int ans{0};
        while (!pq.empty() && deleted < len / 2) {
            int t = pq.top();
            pq.pop();
            deleted += t;
            ++ans;
        }
        return ans;
    }
};