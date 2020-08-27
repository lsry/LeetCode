package L200;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LeetCode0207 {
    public boolean canFinishInOrder(int numCourses, int[][] prerequisites) {
        List<HashSet<Integer>> ls = new ArrayList<>(numCourses); // 入度表
        for (int i = 0;i < numCourses;++i) {
            ls.add(new HashSet<>());
        }
        for (int[] pre : prerequisites) {
            ls.get(pre[0]).add(pre[1]);
        }
        Queue<Integer> qu = new LinkedList<>();
        for (int i = 0;i < numCourses;++i) {
            if (ls.get(i).isEmpty()) {
                qu.offer(i);
            }
        }
        int course = 0;
        while (!qu.isEmpty()) {
            int cur = qu.poll();
            ++course;
            for (int i = 0;i < numCourses;++i) {
                HashSet<Integer> hs = ls.get(i);
                if (!hs.isEmpty() && hs.contains(cur)) {
                    hs.remove(cur);
                    if (hs.isEmpty()) {
                        qu.offer(i);
                    }
                }
            }
        }
        return course == numCourses;
    }

    public boolean canFinishBFS(int numCourses, int[][] prerequisites) {
        List<List<Integer>> ls = new ArrayList<>(numCourses); // 出边表
        int[] inedges = new int[numCourses];
        for (int i = 0;i < numCourses;++i) {
            ls.add(new ArrayList<>());
        }
        for (int[] pre : prerequisites) {
            ls.get(pre[1]).add(pre[0]);
            ++inedges[pre[0]];
        }
        Queue<Integer> qu = new LinkedList<>();
        for (int i = 0;i < numCourses;++i) {
            if (inedges[i] == 0) {
                qu.offer(i);
            }
        }
        int course = 0;
        while (!qu.isEmpty()) {
            int cur = qu.poll();
            ++course;
            for (int out : ls.get(cur)) {
                --inedges[out];
                if (inedges[out] == 0) {
                    qu.offer(out);
                }
            }
        }
        return course == numCourses;
    }
}