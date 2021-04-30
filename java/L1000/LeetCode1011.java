package L1000;

public class LeetCode1011 {
    public int shipWithinDays(int[] weights, int D) {
        int rw = 0, lw = 0;  // 最小载重应该大于等于货物最大值
        for (int weight : weights) {
            rw += weight;
            lw = Math.max(lw, weight);
        }
        int res = Integer.MAX_VALUE;
        while (lw <= rw) {
            int mw = lw + (rw - lw) / 2;
            int d = possibleDay(weights, mw);
            if (d == D) {
                res = Math.min(mw, res);
                rw = mw - 1;
            } else if (d > D) {
                lw = mw + 1;
            } else {
                rw = mw - 1;
            }
        }
        return res == Integer.MAX_VALUE ? lw : res;
    }

    private int possibleDay(int[] weights, int mw) {
        int d = 0;
        for (int i = 0;i < weights.length;) {
            d += 1;
            int cw = 0;
            if (cw + weights[i] > mw) { // 有可能限定重量过小，导致一个也过不去
                return weights.length + 1;
            }
            while (i < weights.length && cw + weights[i] < mw) {
                cw += weights[i];
                ++i;
            }
        }
        return d;
    }
}
