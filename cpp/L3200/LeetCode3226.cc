class Solution {
public:
    int minChanges(int n, int k) {
        int ans{0};
        for (int i = 0;i < 32;++i) {
            int x1 = (n >> i) & 1;
            int x2 = (k >> i) & 1;
            if (x1 == 0 && x2 == 1) {
                return -1;
            } else if (x1 != x2) {
                ++ans;
            }
        }
        return ans;
    }
};