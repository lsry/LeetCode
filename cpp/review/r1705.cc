#include <vector>
using std::vector;
#include <cctype>
#include <string>
using std::string;
#include <unordered_map>

/**
 * C[j] - C[i] == N[j] - N[i]
 * C[j] - N[j] == C[i] - N[i]
 */

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int low{-1};
        int maxLen{0};
        std::unordered_map<int, int> map;
        map[0] = -1;
        int num{0}, chars{0};
        for (int i = 0;i < array.size();++i) {
            if (std::isdigit(array[i][0])) {
                ++num;
            } else {
                ++chars;
            }
            auto it{map.find(chars - num)};
            if (it != map.end()) {
                int len{i - it->second};
                if (len > maxLen) {
                    maxLen = len;
                    low = it->second;
                }
            } else {
                map[chars - num] = i;
            }
        }
        vector<string> res;
        res.reserve(maxLen);
        for (int i = low + 1;i - low <= maxLen;++i) {
            res.push_back(array[i]);
        }
        return res;
    }
};