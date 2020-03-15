public class LeetCode0121 {
    /**
     * 交易一次的最大利润
     * 在卖出前，应该选择之前的日子中价格最低的一点买入
     */
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        int profit = 0;
        int buy = prices[0];
        for (int i = 1;i < prices.length;++i) {
            if (prices[i] > buy) {
                profit = Math.max(profit, prices[i] - buy);
            } else if (prices[i] < buy) {
                buy = prices[i];
            }
        }
        return profit;
    }
}