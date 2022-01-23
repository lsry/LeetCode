package L2000;

public class LeetCode2029 {
    public boolean stoneGameIX(int[] stones) {
        int[] count = new int[3];
        for (int stone : stones) {
            count[stone % 3]++;
        }
        return count[0] % 2 == 0 ? !(count[1] == 0 || count[2] == 0) : !(Math.abs(count[1] - count[2]) <= 2);
    }
}
