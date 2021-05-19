package L1400;

import java.util.PriorityQueue;

public class LeetCode1482 {
    public int minDaysTLE(int[] bloomDay, int m, int k) {
        if (m * k > bloomDay.length) {
            return -1;
        }
        final int N = bloomDay.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[1] - b[1];
        });
        for (int i = 0;i < N;++i) {
            pq.offer(new int[]{i, bloomDay[i]});
        }
        boolean[] flags = new boolean[N];
        while (!pq.isEmpty()) {
            int[] ids = pq.poll();
            flags[ids[0]] = true;
            if (checkTLE(flags, m, k)) {
                return ids[1];
            }
        }
        return -1;
    }

    private boolean checkTLE(boolean[] flags, int m, int k) {
        int f = 0;
        for (int i = 0;i < flags.length;) {
            if (flags[i]) {
                int j = 0;
                for (;j < k && i + j < flags.length;++j) {
                    if (flags[i + j] == false) {
                        break;
                    }
                }
                if (j == k) {
                    f += 1;
                    i += k;
                } else {
                    ++i;
                }
            } else {
                ++i;
            }
        }
        return f >= m;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        if (bloomDay.length < m * k) {
            return -1;
        }
        int low = Integer.MAX_VALUE, high = -1;
        for (int day : bloomDay) {
            if (day < low) {
                low = day;
            }
            if (day > high) {
                high = day;
            }
        }
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    private boolean check(int[] bloomDay, int m, int k, int day) {
        int f = 0;
        int count = 0;
        for (int bday : bloomDay) {
            if (bday > day) {
                count = 0;
            } else {
                count += 1;
                if (count == k) {
                    f += 1;
                    count = 0;
                }
            }
        }
        return f >= m;
    }
}
