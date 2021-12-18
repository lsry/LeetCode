package L600;

import java.util.Arrays;
import java.util.PriorityQueue;

public class LeetCode0630 {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int sum = 0;
        for (int[] course : courses) {
            if (sum + course[0] <= course[1]) {
                sum += course[0];
                pq.offer(course[0]);
            } else {
                sum += course[0];
                pq.offer(course[0]);
                sum -= pq.poll();
            }
        }
        return pq.size();
    }
}
