package L600;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
}

public class LeetCode0690 {
    public int getImportance(List<Employee> employees, int id) {
        HashMap<Integer, Employee> map = new HashMap<>(employees.size());
        for (Employee e : employees) {
            map.put(e.id, e);
        }
        if (!map.containsKey(id)) {
            return 0;
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(id);
        int ans = 0;
        while (!queue.isEmpty()) {
            int idt = queue.poll();
            Employee e = map.get(idt);
            ans += e.importance;
            for (Integer i : e.subordinates) {
                queue.offer(i);
            }
        }
        return ans;
    }
}
