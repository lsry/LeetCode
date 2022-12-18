#include <vector>
#include <string>
using std::string;

class Solution {
    int beautyValue(std::vector<std::vector<int>> &pre, std::size_t i, std::size_t j) {
        int maxV = -1, minV = -1;
        for (int k = 0;k < 26;++k) {
            int v = pre[k][j] - pre[k][i];
            if (v == 0) {
                continue;
            } else if (maxV == -1) {
                maxV = v;
                minV = v;
            } else if (v > maxV) {
                maxV = v;
            } else if (v < minV) {
                minV = v;
            }
        }
        return maxV - minV;
    }
public:
    int beautySum(string s) {
        std::size_t sz{s.size()};
        if (sz == 0) {
            return 0;
        }
        std::vector<std::vector<int>> pre(26, std::vector<int>(sz + 1, 0));
        for (std::size_t i{1};i <= sz;++i) {
            for (int k = 0;k < 26;++k) {
                pre[k][i] = pre[k][i - 1];
            }
            int id = s[i - 1] - 'a';
            pre[id][i] = pre[id][i - 1] + 1;
        }
        int ans{0};
        for (std::size_t i{1};i < sz;++i) {
            for (std::size_t j{i + 1};j <= sz;++j) {
                ans += beautyValue(pre, i - 1, j);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.beautySum("aabcb");
    return 0;
}
