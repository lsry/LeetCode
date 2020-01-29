public class LeetCode0492 {
    public int[] constructRectangle(int area) {
        int L = (int) Math.sqrt(area);
        if (L * L == area) {
            return new int[]{L,L};
        }
        for (int i = L;i > 0;--i) {
            if (area % i == 0) {
                int W = area / i;
                return new int[]{Math.max(i, W),Math.min(W, i)};
            }
        }
        return new int[]{area,1};
    }
}