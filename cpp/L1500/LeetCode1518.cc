class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans{numBottles};
        for (int cur{0};numBottles + cur >= numExchange;) {
            int bottle = (numBottles + cur) / numExchange;
            cur = (numBottles + cur) % numExchange;
            ans += bottle;
            numBottles = bottle;
        }      
        return ans;
    }
};