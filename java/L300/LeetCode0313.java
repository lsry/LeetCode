package L300;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LeetCode0313 {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int res = 1;
        final int N = primes.length;
        List<Queue<Integer>> qus = new ArrayList<>(N);
        for (int i = 0;i < N;++i) {
            qus.add(new LinkedList<>());
        }
        qus.get(0).add(1);
        for (int i = 2;i <= n;++i) {
            int min = qus.get(0).size() == 0 ? primes[0] : qus.get(0).peek() * primes[0];
            int index = 0;
            for (int j = 1;j < N;++j) {
                if (qus.get(j).size() == 0) {
                    continue;
                }
                int cur = qus.get(j).peek() * primes[j];
                if (cur < min) {
                    min = cur;
                    index = j;
                } else if (cur == min) {
                    qus.get(j).poll();
                }
            }
            res = min;
            Queue<Integer> qu = qus.get(index);
            if (!qu.isEmpty()) {
                int x = qu.poll();
                if (index + 1 < N) {
                    qus.get(index + 1).offer(x);
                }
            }
            qus.get(0).offer(min);
        }
        return res;
    }

    public static void main(String[] args) {
        LeetCode0313 code = new LeetCode0313();
        System.out.println(code.nthSuperUglyNumber(12, new int[]{2,7,13,19}));
    }
}