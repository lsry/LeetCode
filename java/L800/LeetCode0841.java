package L800;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * 本质证明图的连通性
 */
public class LeetCode0841 {
    private boolean[] visited;

    public boolean canVisitAllRoomsDFS(List<List<Integer>> rooms) {
        visited = new boolean[rooms.size()];
        helper(rooms, 0);
        for (boolean b : visited){
            if (b == false){
                return false;
            }
        }
        return true;
    }

    public void helper(List<List<Integer>> rooms,int index){
        visited[index] = true;
        int size = rooms.size();
        if (index >= size){
            return;
        }
        List<Integer> li = rooms.get(index);
        for (Integer i : li){
            if (visited[i] == false){
                helper(rooms, i);
            }
        }
    }

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        final int N = rooms.size();
        boolean[] visit = new boolean[N];
        Queue<Integer> qu = new LinkedList<>();
        qu.offer(0);
        while (!qu.isEmpty()) {
            int room = qu.poll();
            visit[room] = true;
            List<Integer> keys = rooms.get(room);
            if (keys.size() > 0) {
                for (int key : keys) {
                    if (!visit[key]) {
                        qu.offer(key);
                    }
                }
            }
        }
        for (boolean b : visit){
            if (b == false){
                return false;
            }
        }
        return true;
    }
}