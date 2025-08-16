class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        } 
        int ans{0};
        for (int i = 0;i < 31;++i) {
            if (((n >> i) & 1) == 1) {
                ++ans;
            }
        }
        return ans == 1;
    }
};