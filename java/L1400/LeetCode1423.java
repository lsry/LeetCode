package L1400;

import java.util.Arrays;

public class LeetCode1423 {
    public int maxScore(int[] cardPoints, int k) {
        int sum  = Arrays.stream(cardPoints).sum();
        int maxScore = 0;
        int remain = 0;
        int l = 0, r = 0;
        for (;r < cardPoints.length - k;++r) {
            remain += cardPoints[r];
        }
        maxScore = sum - remain;
        for (r = k;r < cardPoints.length;++r) {
            ++l;
            remain = remain + cardPoints[r] - cardPoints[l - 1];
            maxScore = Math.max(maxScore, sum - remain);
        }
        return maxScore;
    }
}
