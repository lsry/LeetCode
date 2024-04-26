#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        int N = 1 << 9;
        for (int x = 1;x < N;++x) {
            vector<int> path;
            int sum{0};
            for (int i = 0;i < 9;++i) {
                if (((x >> i) & 1) == 1) {
                    path.push_back(i + 1);
                    sum += i + 1;
                }
            }
            if (sum == n && path.size() == k) {
                res.push_back(path);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    s.combinationSum3(3, 7);
}