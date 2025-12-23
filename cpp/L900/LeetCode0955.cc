#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int M = strs.size(), N = strs[0].size();
        int ans{0};
        vector<int> indics;
        for (int i = 0;i < M - 1;++i) {
            indics.emplace_back(i);
        }
        for (int j = 0;j < N;++j) {
            vector<int> newIds;
            bool flag{true};
            for (int idx : indics) {
                if (strs[idx][j] > strs[idx + 1][j]) {
                    flag = false;
                    break;
                } else if (strs[idx][j] == strs[idx + 1][j]) {
                    newIds.emplace_back(idx);
                }
            }
            if (!flag) {
                ++ans;
            } else {
                indics = newIds;
            }
        }
        return ans;
    }
};
