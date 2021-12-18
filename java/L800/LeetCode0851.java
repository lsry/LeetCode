package L800;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class LeetCode0851 {
    private static class Person {
        public int pid;

        public Set<Integer> bottom;

        public Person(int pid) {
            this.pid = pid;
            bottom = new HashSet<>();
        }
    }
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        if (quiet == null || quiet.length == 0) {
            return new int[0];
        }
        HashMap<Integer, Person> persons = new HashMap<>();
        for (int i = 0;i < quiet.length;++i) {
            persons.put(i, new Person(i));
        }
        for (int[] rich : richer) {
            Person front = persons.get(rich[0]);
            front.bottom.add(rich[1]);
            Person tail = persons.get(rich[1]);
            bfsBottom(persons, quiet, tail, rich[0]);
            if (quiet[front.pid] < quiet[tail.pid]) {
                tail.pid = front.pid;
            }
        }
        int[] ans = new int[quiet.length];
        for (int i = 0;i < quiet.length;++i) {
            Person p = persons.get(i);
            ans[i] = p.pid == -1 ? i : p.pid;
        }
        return ans;
    }
    private void bfsBottom(HashMap<Integer, Person> persons, int[] quiet, Person p, int richer) {
        if (quiet[richer] < quiet[p.pid]) {
            p.pid = richer;
        }
        for (Integer i : p.bottom) {
            Person next = persons.get(i);
            bfsBottom(persons, quiet, next, richer);
        }
    }
}
