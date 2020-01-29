public class LeetCode0592 {
    private int[] res = new int[]{0,1};

    public int gcd(int up, int down) {
        if (down > up) {
            int x = down;
            down = up;
            up = x;
        }
        return down == 0 ? up : gcd(down, up % down);
    }

    public void add(int[] other) {
        int t = res[0] * other[1] + other[0] * res[1];
        if (t == 0) {
            res[0] = 0;
            res[1] = 1;
            
        } else {
            int t2 = res[1] * other[1];
            int g = gcd(Math.abs(t2), Math.abs(t));
            res[0] = t / g;
            res[1] = t2 / g;
        }  
    }

    // 头结点辅助计算
    public String fractionAddition(String expression) {
        int[] cur = new int[]{0,1};
        int flag = 1;
        int index = 0;
        if (expression.charAt(index) == '-') {
            flag = -1;
            index++;
        }
        int t = 0;
        for (;index < expression.length();++index) {
            char ch = expression.charAt(index);
            if (ch == '/') {
                cur[0] = t * flag;
                t = 0;
            } else if (ch == '+') {
                cur[1] = t;
                add(cur);
                cur = new int[]{0,1};
                t = 0;
                flag = 1;
            } else if (ch == '-') {
                cur[1] = t;
                add(cur);
                cur = new int[]{0,1};
                t = 0;
                flag = -1;
            } else {
                t = t * 10 + (ch - '0');
            }
        }
        cur[1] = t;
        add(cur);
        return res[0] + "/" + res[1];
    }

    public static void main(String[] args) {
        LeetCode0592 code = new LeetCode0592();
        System.out.println(code.gcd(4,8));
        System.out.println(code.gcd(8,4));
    }
}