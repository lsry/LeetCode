class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans{numBottles};
        for (;numBottles >= numExchange;++numExchange) {
            ++ans;
            numBottles -= numExchange - 1;
        }      
        return ans;
    }
};