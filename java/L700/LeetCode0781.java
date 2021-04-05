package L700;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0781 {
    public int numRabbits(int[] answers) {
        if (answers == null || answers.length == 0) {
            return 0;
        }
        int rabbit = 0;
        List<Integer> colors = new ArrayList<>();
        List<Integer> remain = new ArrayList<>();
        for (int n : answers) {
            boolean flag = true;
            for (int i = 0;i < colors.size();++i) {
                if (colors.get(i) == n + 1 && remain.get(i) > 0) {
                    flag = false;
                    remain.set(i, remain.get(i) - 1);
                    break;
                }
            }
            if (flag) {
                colors.add(n + 1);
                remain.add(n);
            }
        }
        for (int cn : colors) {
            rabbit += cn;
        }
        return rabbit;
    }
}
