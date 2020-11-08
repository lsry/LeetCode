package L100;

public class LeetCode0122 {
    /**
     * Time Limit Exceed
     */
    public int maxProfitTLE(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        return Math.max(getProfitTLE(prices, 1, 0, false), getProfitTLE(prices, 1, 0-prices[0], true));
    }

    private int getProfitTLE(int[] prices, int index, int profit, boolean buy) {
        if (index >= prices.length) {
            return profit;
        }
        if (buy) {
            int sell = getProfitTLE(prices, index + 1, profit + prices[index], !buy);
            int notSell = getProfitTLE(prices, index + 1, profit, buy);
            return Math.max(sell, notSell);
        }
        int buyStock = getProfitTLE(prices, index + 1, profit - prices[index], true);
        int notBuyStock = getProfitTLE(prices, index + 1, profit, false);
        return Math.max(buyStock, notBuyStock);
    }

    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        int[][] profit = new int[prices.length][2];
        profit[0][0] = 0 - prices[0];
        profit[0][1] = 0;
        for (int i = 1;i < profit.length;++i) {
            profit[i][0] = Math.max(profit[i - 1][0], profit[i - 1][1] - prices[i]);
            profit[i][1] = Math.max(profit[i - 1][1], profit[i - 1][0] + prices[i]);
        }
        return profit[prices.length - 1][1];
    }
}
