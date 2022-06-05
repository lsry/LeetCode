#include <vector>
using std::vector;
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <numeric>
#include <cmath>

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        vector<int> wc1, wc2;
        std::size_t wz{words.size()};
        for (std::size_t i{0};i < wz;++i) {
            if (word1 == words[i]) {
                wc1.push_back(i);
            } else if (word2 == words[i]) {
                wc2.push_back(i);
            }
        }
        int dis = std::numeric_limits<int>::max();
        for (int const c1 : wc1) {
            for (int const c2 : wc2) {
                int diff = std::abs(c1 - c2);
                dis = std::min(diff, dis);
            }
        }
        return dis;
    }
};