#include <string>
#include <unordered_map>
using std::string;
#include <vector>
using std::vector;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        std::unordered_map<int, int> countMap;
        for (string const &word : words) {
            int x{0};
            for (char c : word) {
                x = x | (1 << (c - 'a'));
            }
            countMap[x] += 1;
        }
        int ans{0};
        for (auto const &[_, v] : countMap) {
            ans += v * (v - 1) / 2;
        }
        return ans;
    }
};