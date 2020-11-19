package L400;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class LeetCode0406{
    /**
     * 身高逆序排列
     */
    public int[][] reconstructQueueReverse(int[][] people) {
        Arrays.sort(people, (p1,p2) -> {
            if (p1[0] != p2[0]){
                return p2[0] - p1[0];
            } else {
                return p1[1] - p2[1];
            }
        });
        List<int[]> arrList = new LinkedList<>();
        for (int[] ar : people){
            arrList.add(ar[1], ar);
        }
        return arrList.toArray(new int[arrList.size()][2]);
    }

    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (p1, p2) -> {
            return (p1[0] != p2[0]) ? p1[0] - p2[0] : p2[1] - p1[1];
        });
        int[][] res = new int[people.length][];
        for (int[] p : people) {
            int pos = p[1] + 1;
            int i = 0;
            for (;i < res.length;++i) {
                if (res[i] == null) {
                    --pos;
                    if (pos == 0) {
                        res[i] = p;
                        break;
                    }
                }
            }
        }
        return res;
    }
}