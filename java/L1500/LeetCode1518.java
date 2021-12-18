package L1500;

public class LeetCode1518 {
    public int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        int noWater = 0;
        while (numBottles != 0) {
            int t = (numBottles + noWater) / numExchange;
            sum += t;
            noWater = (numBottles + noWater) % numExchange;
            numBottles = t;
        }
        return sum;
    }
}
