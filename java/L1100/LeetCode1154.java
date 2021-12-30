package L1100;

public class LeetCode1154 {
    private static final int[] dates = new int[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public int dayOfYear(String date) {
        String[] days = date.split("-");
        int year = Integer.parseInt(days[0]);
        int month = Integer.parseInt(days[1]);
        int day  = Integer.parseInt(days[2]);
        int curDayTh = 0;
        for (int i = 1;i < month;++i) {
            if (i == 2) {
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                    curDayTh += 29;
                } else {
                    curDayTh += 28;
                }
            } else {
                curDayTh +=  dates[i];
            }
        }
        return curDayTh + day;
    }
}
