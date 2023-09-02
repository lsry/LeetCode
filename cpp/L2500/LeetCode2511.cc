#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans{0};
        int n = forts.size();
        bool blank{false};
        int count{0};
        for (int i{0};i < n;++i) {
            if (forts[i] == -1) {
                blank = true;
                count = 0;
            } else if (forts[i] == 0) {
                if (blank) {
                    ++count;
                }
            } else if (forts[i] == 1) {
                ans = std::max(ans, count);
                blank = false;
                count = 0;
            }
        }    
        blank = false;
        count = 0;  
        for (int i = n - 1;i >= 0;--i) {
            if (forts[i] == -1) {
                blank = true;
                count = 0;
            } else if (forts[i] == 0) {
                if (blank) {
                    ++count;
                }
            } else if (forts[i] == 1) {
                ans = std::max(ans, count);
                blank = false;
                count = 0;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v{1,0,0,-1,0,0,-1,0,0,1};
    Solution s;
    s.captureForts(v);
}