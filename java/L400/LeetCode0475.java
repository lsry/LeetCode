package L400;

import java.util.Arrays;

public class LeetCode0475 {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int min = 0, max = Math.max(houses[houses.length - 1], heaters[heaters.length - 1]) - houses[0];
        while (min < max) {
            int mid = (max + min) / 2;
            if (check(houses, heaters, mid)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        return max;
    }

    private boolean check(int[] houses, int[] heaters, int radius) {
        int next = 0;
        for (int i = 0;i < heaters.length && next < houses.length;++i) {
            if (houses[next] < heaters[i] - radius) {
                return false;
            }
            while (next < houses.length && (houses[next] <= heaters[i] + radius && houses[next] >= heaters[i] - radius)) {
                ++next;
            }
        }
        return next >= houses.length;
    }
}