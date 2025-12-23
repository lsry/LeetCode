#include <vector>
using std::vector;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int N = strategy.size();
        vector<long long> profitSum(N + 1, 0);
        vector<long long> pricesSum(N + 1, 0);
        for (int i = 0;i < N;++i) {
            profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i];
            pricesSum[i + 1] = pricesSum[i] + prices[i];
        }
        long long int profit{profitSum[N]};
        for (int i = 1;i <= N - k + 1;++i) {
            long long int leftProfit = profitSum[i - 1];
            int x = i + k / 2, y = i + k - 1;
            long long int priceProfit = x <= N && y <= N ? pricesSum[y] - pricesSum[x - 1] : 0;
            long long int rightProfit = y >= 0 && y <= N ? profitSum[N] - profitSum[y] : 0;
            profit = std::max(profit, leftProfit + priceProfit + rightProfit);
        }
        return profit;
    }
};

int main() {
    Solution s;
    vector<int> v1{4,7,13}, v2{-1, -1, 0};
    s.maxProfit(v1, v2, 2);
}
