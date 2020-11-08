package L1000;

public class LeetCode1014 {
    /**
     * 由 ans = A[i] + A[j] + i - j
     * 得到：ans = (A[i] + i) + (A[j] - j)
     */
    public int maxScoreSightseeingPair(int[] A) {
        int ans = 0;
        int aii = A[0] + 0;
        for (int i = 1;i < A.length;++i) {
            ans = Math.max(ans, aii + A[i] - i);
            if (A[i] + i > aii) {
                aii = A[i] + i;
            }            
        }
        return ans;
    }
}