package L700;

public class LeetCode0714 {
    public int maxProfit(int[] prices, int fee) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int hold = -prices[0];
        int not_hold = 0;
        for (int i = 1;i < prices.length;++i) {
            int h = hold, n = not_hold;
            hold = Math.max(h, n + prices[i]);
            not_hold = Math.max(n, h + prices[i] - 2);
        }
        return Math.max(hold, not_hold);
    }
}
