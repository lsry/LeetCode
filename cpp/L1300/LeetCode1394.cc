#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::unordered_map<int, int> freqs;
        for (int x : arr) {
            freqs[x]++;
        }
        int ans{-1};
        for (auto const &[k, v] : freqs) {
            if (k == v && k > ans) {
                ans = k;
            }
        }
        return ans;
    }
};