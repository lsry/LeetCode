#include <vector>
using std::vector;

class Solution {
public:
    /**
     * 考慮 dp[i][k]: 代表以 i 元素結尾，刪除 k 次的最大和
     */
    int maximumSum(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        int no{arr[0]}, de{0};
        int ans{arr[0]};
        for (int i = 1;i < arr.size();++i) {
            int n1 = std::max(no, 0) + arr[i];
            int d1 = std::max(de + arr[i], no);
            no = n1;
            de = d1;
            ans = std::max(ans, std::max(no, de));
        }
        return ans;
    }
};