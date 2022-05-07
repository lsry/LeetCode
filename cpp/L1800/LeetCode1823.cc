class Solution {
public:
    int findTheWinner(int n, int k) {
        int dis = 0;
        for (int i{2};i <= n;++i) {
            dis = (dis + k) % i;
        }
        return dis + 1;
    }
};