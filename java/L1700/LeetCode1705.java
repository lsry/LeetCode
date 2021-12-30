package L1700;

import java.util.PriorityQueue;

public class LeetCode1705 {
    private static class Apple {
        public int deadDay;

        public int count;

        public Apple(int day, int count) {
            this.deadDay = day;
            this.count = count;
        }
    }

    public int eatenApples(int[] apples, int[] days) {
        PriorityQueue<Apple> pq = new PriorityQueue<>((a, b) -> {
            if (a.deadDay == b.deadDay) {
                return b.count - a.count;
            } else {
                return a.deadDay - b.deadDay;
            }
        });
        int appleCount = 0;
        int i = 0;
        for (;i < apples.length;++i) {
            if (apples[i] != 0) {
                pq.offer(new Apple(days[i] + i, apples[i]));
            }
            while (!pq.isEmpty() && (pq.peek().deadDay <= i || pq.peek().count == 0)) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
                Apple apple = pq.peek();
                ++appleCount;
                apple.count -= 1;
                if (apple.count == 0) {
                    pq.poll();
                }
            }
        }
        while (!pq.isEmpty()) {
            while (!pq.isEmpty() && (pq.peek().deadDay <= i || pq.peek().count == 0)) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
                Apple apple = pq.poll();
                int canEat = Math.min(apple.count, apple.deadDay - i);
                i += canEat;
                appleCount += canEat + 1;
            }
        }
        return appleCount;
    }

    public static void main(String[] args) {
        LeetCode1705 code = new LeetCode1705();
        code.eatenApples(new int[]{1,2,3,5,2}, new int[]{3,2,1,4,2});
    }
}
