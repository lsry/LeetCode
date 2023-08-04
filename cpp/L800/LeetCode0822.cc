#include <vector>
using std::vector;
#include <unordered_map>

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ans{200001};
        std::unordered_map<int, vector<int>> mp;
        int N = fronts.size();
        for (int i = 0;i < N;++i) {
            mp[fronts[i]].push_back(i);
        }
        for (int i = 0;i < N;++i) {
            bool flag{true};
            for (int id : mp[fronts[i]]) {
                if (backs[id] == fronts[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = std::min(ans, fronts[i]);
            }
        }
        for (int i = 0;i < N;++i) {
            bool flag{true};
            for (int id : mp[backs[i]]) {
                if (backs[id] == backs[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = std::min(ans, backs[i]);
            }
        }
        return ans == 200001 ? 0 : ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> f{1,1}, b{1,2};
    s.flipgame(f, b);
    return 0;
}
