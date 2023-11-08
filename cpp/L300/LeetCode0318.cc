#include <utility>
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int N = words.size();
        vector<std::pair<int, int>> vp(N);
        for (int i = 0;i < N;++i) {
            for (char const c : words[i]) {
                vp[i].first |= (1 << (c - 'a'));
            }
            vp[i].second = words[i].size();
        }
        int ans{0};
        for (int i = 0;i < N;++i) {
            for (int j{i + 1};j < N;++j) {
                if ((vp[i].first & vp[j].first) == 0) {
                    ans = std::max(ans, vp[i].second * vp[j].second);
                }
            }
        }
        return ans;
    }
};