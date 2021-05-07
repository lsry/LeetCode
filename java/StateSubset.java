public class StateSubset {
    public static void main(String[] args) {
        int[] set = new int[]{1, 2};
        int state = (1 << (set.length)) - 1;
        for (int i = state;i != 0; i = (i - 1) & state) {
            int x = i;
            int a = 0;
            while (x != 0) {
                if ((x & 1) == 1) {
                    System.out.print(set[a] + "\t");
                }
                x = x >> 1;
                ++a;
            }
            System.out.println();
        }
    }
}
