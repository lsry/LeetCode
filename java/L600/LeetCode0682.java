package L600;

public class LeetCode0682 {
    public int calPoints(String[] ops) {
        int points = 0;
        int[] arr = new int[ops.length + 1];
        int index = 0;
        for (String op : ops) {
            if (op.equals("+")) {
                int t = arr[index - 1] + arr[index - 2];
                points += t;
                arr[index] = t;
                index++;
            } else if (op.equals("D")) {
                int t = arr[index - 1] * 2;
                points += t;
                arr[index] = t;
                index++;
            } else if (op.equals("C")) {
                points -= arr[index - 1];
                index--;
            } else {
                int t = Integer.valueOf(op);
                points += t;
                arr[index] = t;
                index++;
            }
        }
        return points;
    }
}