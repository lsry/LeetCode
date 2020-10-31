package L900;

import java.util.HashSet;
import java.util.Set;

public class LeetCode0945 {
    public int minIncrementForUniqueTLE(int[] A) {
        int step = 0;
        Set<Integer> si = new HashSet<>();
        for (int a : A) {
            while (si.contains(a)) {
                ++a;
                ++step;
            }
            si.add(a);
        }
        return step;
    }

    public int minIncrementForUnique(int[] A) {        
        int[] A1 = new int[40000];
        for (int a : A) {
            A1[a]++;
        }
        int step = 0;
        int wait = 0;
        for (int i = 0;i < A1.length;++i) {
            if (A1[i] > 1) {
               step -= i * (A1[i] - 1); 
               wait += A1[i] - 1;
            } else if (A1[i] == 0 && wait > 0) {
                step += i;
                --wait;
            }
        }
        for (int i = 40000;wait > 0;++i) {
            step += i;
            --wait;
        }
        return step;
    }
}