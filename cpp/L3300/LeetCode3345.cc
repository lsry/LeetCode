class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n;;++i) {
            int p{1};
            for (int j = i;j > 0;j /= 10) {
                p *= (j % 10);
            }
            if (p % t == 0) {
                return i;
            }
        }
        return -1;
    }
};
