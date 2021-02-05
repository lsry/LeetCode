package L1300;

import java.util.Arrays;

public class LeetCode1356 {
    private class Num implements Comparable<Num> {
        private int num;
        private int one;

        public Num(int n) {
            this.num = n;
            this.one = 0;
            while (n > 0) {
                ++this.one;
                n = n & (n - 1);
            }
        }

        @Override
        public int compareTo(Num o) {
            return (this.one == o.one) ? this.num - o.num : this.one - o.one;
        }
    }
    public int[] sortByBits(int[] arr) {
        return Arrays.stream(arr).boxed().map(Num::new).sorted().mapToInt(n->n.num).toArray();
    }
}
