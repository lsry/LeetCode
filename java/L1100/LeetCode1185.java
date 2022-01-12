package L1100;

public class LeetCode1185 {

    private static final String[] week = new String[]{"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};

    private static final int[] dayOfMonth = new int[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    public String dayOfTheWeek(int day, int month, int year) {
        int days = 0;
        for (int i = 1971;i < year;++i) {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
                days += 366;
            } else {
                days += 365;
            }
        }
        for (int i = 1;i < month;++i) {
            if (i == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
                days += 29;
            } else {
                days += dayOfMonth[i];
            }
        }
        days += day - 1;
        return week[days % 7];
    }
}
