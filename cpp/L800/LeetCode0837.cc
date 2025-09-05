class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k > n) {
            return 0;
        }
        if (k - 1 + maxPts <= n) {
            return 1.0;
        }
        double p{0.0};
        for (int i = 0;i <= k - 1;++i) {
            p += (maxPts - n + i) * 1.0 / maxPts;
        }
        return 1 - p;
    }
};